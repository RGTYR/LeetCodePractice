class Solution:
	def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
		result = []
		length1 = len(arr1) - 1
		length2 = len(arr2) - 1
		length = length1 if length1 > length2 else length2

		carry = 0

		while length >= 0 or carry != 0:
			term1 = arr1[length1] if length1 >= 0 else 0
			term2 = arr2[length2] if length2 >= 0 else 0

			sum = term1 + term2 + carry
			carry = 0

			if sum > 1:
				sum -= 2
				carry = -1
			elif sum < 0:
				sum += 2
				carry = 1

			result.append(sum)
			length1 -= 1
			length2 -= 1
			length -= 1

		result.reverse()

		while (result[0] == 0 and len(result) > 1):
			result.pop()

		return result