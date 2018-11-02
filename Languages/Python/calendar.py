# Python program to display calendar of given month of the year

# import module
import calendar

yy = 2018
mm = 11

# To ask month and year from the user
# yy = int(input("Enter year: "))
# mm = int(input("Enter month: "))

# display the calendar
print(calendar.month(yy, mm))