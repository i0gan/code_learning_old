from selenium import webdriver
# 实现打开网站

# 打开浏览器驱动
wd = webdriver.Chrome('/usr/bin/chromedriver')
# get方法请求 url
wd.get('https://www.bilibili.com')

print("ok")
