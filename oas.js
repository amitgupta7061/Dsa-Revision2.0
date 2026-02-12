(async function () {
    const GEMINI_API_KEY = "---------------------------------------------------";
    function getQuestion() {
        const qElem = document.getElementsByClassName("QuestionDescription")[0];
        if (!qElem) return null;
        return qElem.innerText.trim();
    }
    function getOptions() {
        const optionCol = document.getElementById("optionCol");
        if (!optionCol) return [];

        const labels = optionCol.querySelectorAll("label");

        let options = [];

        labels.forEach(label => {
            const text = label.innerText.trim();
            const radio = label.querySelector("input[type=radio]");

            options.push({
                text,
                radio
            });
        });

        return options;
    }
    async function askGemini(question, options) {

        const optionsText = options
            .map((opt, i) => `${i+1}. ${opt.text}`)
            .join("\n");

        const prompt = `
Answer the following MCQ. Return ONLY the correct option text exactly.

Question:
${question}

Options:
${optionsText}

Return only the correct option.
`;

        for (let attempt = 0; attempt < 3; attempt++) {
            try {
                const response = await fetch(
                    `https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key=${GEMINI_API_KEY}`,
                    {
                        method: "POST",
                        headers: {
                            "Content-Type": "application/json"
                        },
                        body: JSON.stringify({
                            contents: [{
                                parts: [{ text: prompt }]
                            }],
                            safetySettings: [
                                { category: "HARM_CATEGORY_HARASSMENT", threshold: "BLOCK_NONE" },
                                { category: "HARM_CATEGORY_HATE_SPEECH", threshold: "BLOCK_NONE" },
                                { category: "HARM_CATEGORY_SEXUALLY_EXPLICIT", threshold: "BLOCK_NONE" },
                                { category: "HARM_CATEGORY_DANGEROUS_CONTENT", threshold: "BLOCK_NONE" }
                            ]
                        })
                    }
                );

                if (response.status === 429) {
                     const waitTime = (attempt + 1) * 2000;
                     console.error(`⏳ Rate limit hit (429). Retrying in ${waitTime/1000}s...`);
                     await new Promise(resolve => setTimeout(resolve, waitTime));
                     continue;
                }

                if (!response.ok) {
                    const errorData = await response.json().catch(() => ({}));
                    console.error("❌ Gemini API Error:", response.status, errorData);
                    return undefined;
                }

                const data = await response.json();

                const answer =
                    data.candidates?.[0]?.content?.parts?.[0]?.text?.trim();
                
                if (!answer) {
                     console.error("❌ Gemini API returned no answer. Data:", JSON.stringify(data));
                }

                return answer;

            } catch (error) {
                console.error("❌ Fetch Error:", error);
                return undefined;
            }
        }

        console.error("❌ Max retries reached. API Quota likely exhausted.");
        return undefined;
    }
    function selectAnswer(answer, options) {

    // ✅ Fallback: if Gemini failed or answer undefined
    if (!answer) {
        console.error("⚠ Gemini returned undefined. Selecting Option A");

        if (options.length > 0) {
            options[0].radio.click();
        }

        return;
    }

    // ✅ Normal matching
    for (let opt of options) {

        if (
            answer.includes(opt.text) ||
            opt.text.includes(answer)
        ) {
            opt.radio.click();
            return;
        }
    }

    // ✅ Fallback if no match found
    console.error("⚠ No match found. Selecting Option A");

    if (options.length > 0) {
        options[0].radio.click();
    }
}

    async function solveQuestion() {

        const question = getQuestion();
        const options = getOptions();

        if (!question) {
            console.error("❌ Error: Question not found in DOM");
            return;
        }

        const answer = await askGemini(question, options);

        selectAnswer(answer, options);
    }
    document.addEventListener("keydown", function (e) {

        if (e.altKey && e.key.toLowerCase() === "a") {
            solveQuestion();
        }

    });

})();
