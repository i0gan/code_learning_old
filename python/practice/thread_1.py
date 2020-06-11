#! /usr/bin/python3
import _thread
import time

# 为线程定义一个函数
def print_time(thread_name, delay):
    count = 0
    while count < 5:
        time.sleep(delay)
        count += 1
        print("%s : %s" % (thread_name, time.ctime(time.time())))

try:
    _thread.start_new_thread(print_time, ("thread - 1", 2))
    _thread.start_new_thread(print_time, ("thread-2", 4))
except:
    print("启动线程失败")

while 1:
    pass