# Problem 2           (4 Points) 
# Write a python program that asks the user to input a date as an integer in the format MMDDYYYY. 
# The program will call a function that prints out the date in the format <Month Name> <day>, <year>

# Sample run: >>>Enter date: 12252014 December 25, 2014 

# In the input the month and the day will always be given as two digits, including leading zero. So the 20th
# of May, 2000 will be entered as 05202000 and the 3rd of December, 2000 will be entered as 12032000.


x = input("Input a date in the format MMDDYYYY: ")

def getDate(x):
	x = str(x)
	d = '1st'
	m = 'January'
	y = x[4:8]
	if(x[0:2] == '01'):
		m = 'January'
	elif(x[0:2] == '02'):
		m = 'February'
	elif(x[0:2] == '03'):
		m = 'March'
	elif(x[0:2] == '04'):
		m = 'April'
	elif(x[0:2] == '05'):
		m = 'May'
	elif(x[0:2] == '06'):
		m = 'June'
	elif(x[0:2] == '07'):
		m = 'July'
	elif(x[0:2] == '08'):
		m = 'August'
	elif(x[0:2] == '09'):
		m = 'September'
	elif(x[0:2] == '10'):
		m = 'October'
	elif(x[0:2] == '11'):
		m = 'November'
	elif(x[0:2] == '12'):
		m = 'December'
	else:
		m = 'Incorrect month syntax - (mm).\n'


	if(x[2:4] == '01'):
		d = '1st'
	elif(x[2:4] == '02'):
		d = '2nd'
	elif(x[2:4] == '03'):
		d = '3rd'
	elif(x[2:4] == '04'):
		d = '4th'
	elif(x[2:4] == '05'):
		d = '5th'
	elif(x[2:4] == '06'):
		d = '6th'
	elif(x[2:4] == '07'):
		d = '7th'
	elif(x[2:4] == '08'):
		d = '8th'
	elif(x[2:4] == '09'):
		d = '9th'
	elif(x[2:4] == '10'):
		d = '10th'
	elif(x[2:4] == '11'):
		d = '11th'
	elif(x[2:4] == '12'):
		d = '12th'
	elif(x[2:4] == '13'):
		d = '13th'
	elif(x[2:4] == '14'):
		d = '14th'
	elif(x[2:4] == '15'):
		d = '15th'
	elif(x[2:4] == '16'):
		d = '16th'
	elif(x[2:4] == '17'):
		d = '17th'
	elif(x[2:4] == '18'):
		d = '18th'
	elif(x[2:4] == '19'):
		d = '19th'
	elif(x[2:4] == '20'):
		d = '20th'
	elif(x[2:4] == '21'):
		d = '21st'
	elif(x[2:4] == '22'):
		d = '22nd'
	elif(x[2:4] == '23'):
		d = '23rd'
	elif(x[2:4] == '24'):
		d = '24th'
	elif(x[2:4] == '25'):
		d = '25th'
	elif(x[2:4] == '26'):
		d = '26th'
	elif(x[2:4] == '27'):
		d = '27th'
	elif(x[2:4] == '28'):
		d = '28th'
	elif(x[2:4] == '29'):
		d = '29th'
	elif(x[2:4] == '30'):
		d = '30th'
	elif(x[2:4] == '31'):
		d = '31st'
	else:
		d = 'Incorrect day syntax (dd)\n'

	print m, d, y

getDate(x)