from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import sys

my_link="www"
my_name="xxx"
my_password="yyy"
my_pin="zzz"
token = sys.argv[1]

driver = webdriver.Firefox()
driver.get(my_link)

for element,entry in [["login",my_name],["passwd",my_password],["passwd1",my_pin+token]]:
	field=driver.find_element_by_name(element)
	field.clear()
	field.send_keys(entry)

field.send_keys(Keys.RETURN)
