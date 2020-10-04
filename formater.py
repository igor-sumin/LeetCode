import sys
import re

PREV = "LeetCode\n========\n\n### Solutions for LeetCode (C++ & Python)\n\n| # | Title | Solution |\n|---| ----- | -------- |\n"

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
		var = ''
		solution = solution.split()
		for sol in solution:
			solution_form = 'Python' if sol == 'py' else 'C++'

			# (209) Group Anagrams (py) -> ./py/209_group_anagrams.py
			local_form = './' + sol + '/' + number + '_' + problem_formater('_', problem) + '.' + sol
			var += '[{}]({}), '.format(solution_form, local_form)

		# remove the extra comma
		var = var[:-2]
		
		candidate = "{0} [{1}]({2}) | {3} |".format(number_form, problem, reference_form, var)
		data.append(candidate + '\n')

		# sorting by the number found in the data: ["|259| ...", "|3567| ...", etc]
		data.sort(
			key=lambda dat: int(re.findall(r'\d+', dat[1:5])[0])
		)

	with open("README.md", "w") as file_obj:
		file_obj.writelines(PREV)
		file_obj.write(
			''.join(map(str, data))
		)

if __name__ == "__main__":
	k = 0
	while k <= 0 or k > 11:
		k = int(input('quantity tasks: '))

	lst_number = []
	lst_problem = []
	lst_solution = []
	for i in range(k):
		print("\nproblem №{}".format(i + 1))

		number = ''
		while not number.isdigit() or int(number) <= 0 or int(number) > 9999:
			number = input('number: ')
			if number.startswith('!'):
				print('')
				sys.exit()

		problem = ''
		while not problem or any([not word.istitle() for word in problem.split() if len(word) > 4]):
			problem = input('name: ')
			if problem.startswith('!'):
				sys.exit()

		solution = ''
		while not solution and (solution != 'py' and solution != 'cpp') and (solution != 'cpp py' and solution != 'py cpp'):
			solution = input('py, cpp: ')
			if solution.startswith('!'):
				sys.exit()

		lst_number.append(number)
		lst_problem.append(problem)
		lst_solution.append(solution)

	formater(lst_number, lst_problem, lst_solution)
	print('\nadding {} solutions'.format(k))