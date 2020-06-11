#!/usr/bin/python
import os
import requests
url = 'https://www.baidu.com'
#os.environ['NO_PROXY'] = 'https://172.28.92.106'
response = requests.get(url, verify = False)
print(response.text)
