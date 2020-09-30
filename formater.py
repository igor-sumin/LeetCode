import sys
import re

prev = "LeetCode\n========\n\n### Solutions for LeetCode (C++ & Python)\n\n| # | Title | Solution |\n|---| ----- | -------- |\n"

def formater(lst_number, lst_problem, lst_solution):
	def problem_formater(sep, problem):
		return sep.join(problem.lower().split())
	
	with open("README.md", "r") as file_obj:
		data = file_obj.readlines()[7:]

	for number, problem, solution in zip(lst_number, lst_problem, lst_solution):
		# |23|   ...
		# |203|  ...
		# |2013| ...
		number_form = '|' + number + '|'.ljust(5 - len(number), ' ')

		# Group Anagrams -> group-anagrams
		reference_form = 'https://leetcode.com/problems/' + problem_formater('-', problem) + '/'

		# py -> Python
		solution_form = 'Python' if solution == 'py' else 'C++'

		# (209) Group Anagrams (py) -> ./py/209_group_anagrams.py
		local_form = './' + solution + '/' + number + '_' + problem_formater('_', problem) + '.' + solution
		
		candidate = "{0} [{1}]({2}) | [{3}]({4}) |".format(number_form, problem, reference_form, solution_form, local_form)
		data.append(candidate + '\n')

		# sorting by the number found in the data: ["|259| ...", "|3567| ...", etc]
		data.sort(
			key=lambda dat: int(re.findall(r'\d+', dat[1:5])[0])
		)

	with open("README.md", "w") as file_obj:
		file_obj.writelines(prev)
		file_obj.write(
			''.join(map(str, data))
		)

if __name__ == "__main__":
	try:
		k = int(input('quantity tasks: '))
		if k <= 0:
			raise Exception("incorrect QUANTITY format")

		lst_number = []
		lst_problem = []
		lst_solution = []
		for i in range(k):
			print("\nproblem №{}".format(i + 1))
			number = input('number: ')
			if not number.isdigit() or int(number) <= 0 or int(number) > 9999:
				raise Exception("incorrect NUMBER format")

			problem = input('name: ')
			if not problem or any([not word.istitle() for word in problem.split() if len(word) > 3]):
				raise Exception("incorrect PROBLEM format")

			solution = input('py, cpp: ')
			if solution != 'py' and solution != 'cpp':
				raise Exception("incorrect SOLUTION format")

			lst_number.append(number)
			lst_problem.append(problem)
			lst_solution.append(solution)

	except Exception as e:
		print(e)
		sys.exit()

	formater(lst_number, lst_problem, lst_solution)
	print('\ndone')