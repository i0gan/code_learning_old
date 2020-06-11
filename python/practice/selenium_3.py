from selenium import webdriver
import time
wd = webdriver.Chrome('/usr/bin/chromedriver')

for i in range(200):
    try:
        wd.get('https://www.bilibili.com/video/BV19z4y197zC?')
        video = wd.find_element_by_class_name('bilibili-player-video')
        video.click()
        time.sleep(15)
        wd.close()
        wd = webdriver.Chrome('/usr/bin/chromedriver')
    except:
        continue