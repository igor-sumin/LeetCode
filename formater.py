import sys


def formater(number, problem, solution):
	def problem_formater(sep, problem):
		return sep.join(problem.lower().split())
	# |23|   ...
	# |203|  ...
	# |2013| ...
	number_form = '|' + number + '|'.ljust(5 - len(number), ' ')

	# Group Anagrams -> group-anagrams
	reference_form = 'https://leetcode.com/problems/' + problem_formater('-', problem) + '/'

	# py -> Python
	solution_form = 'Python' if solution == 'py' else 'C++'

	# (209) Group Anagrams (py) -> ./py/209_group_anagrams.py
	local_form = './' + solution + '/' + number + '_' + problem_formater('_', problem) + solution

	return "{0} [{1}]({2}) | [{3}]({4}) |".format(number_form, problem, reference_form, solution_form, local_form)


if __name__ == "__main__":
	try:
		number = input('number: ')
		if not number.isdigit() or int(number) <= 0 or int(number) > 9999:
			raise Exception("incorrect NUMBER format")

		problem = input('name: ')
		if any([not word.istitle() for word in problem.split() if len(word) > 3]):
			raise Exception("incorrect PROBLEM format")

		solution = input('py, cpp: ')
		if solution != 'py' and solution != 'cpp':
			raise Exception("incorrect SOLUTION format")

	except Exception as e:
		print(e)
		sys.exit()

	print(formater(number, problem, solution))