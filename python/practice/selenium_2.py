from selenium import webdriver
# 根据id 来实现获取元素

# 实现自动百度搜索
# WebDriver 对象
wd = webdriver.Chrome('/usr/bin/chromedriver')
wd.get('https://www.baidu.com')
# 输入框
info = wd.find_element_by_id('kw')
# 搜索按钮
btn = wd.find_element_by_id('su')
# 输入内容
info.send_keys('hello world')
# 点击按钮
#btn.click()