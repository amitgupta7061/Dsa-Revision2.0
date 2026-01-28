#code for binary search including array input and output

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target: return mid
        elif arr[mid] < target: left = mid + 1
        else: right = mid - 1
    return -1
    
# input take array 

n = int(input("Enter number of elements in array: "))
arr = list(map(int, input("Enter the elements of the array: ").split()))
target = int(input("Enter the target value to search: "))   

result = binary_search(arr, target)
if result != -1:
    print(f"Element found at index: {result}")
else:
    print("Element not found in the array.")