#! /usr/bin/python3
#-*- coding: utf-8 -*-
# Author: i0gan、happi0
# API REF:
# https://yooziki.github.io/2020/08/297095/
# https://graia-document.vercel.app/

from graia.broadcast import Broadcast
from graia.application import GraiaMiraiApplication, Session
from graia.application.message.chain import MessageChain
from graia.application.message.elements.internal import Plain
from graia.application.friend import Friend
from graia.application.group import Group
from graia.application.entry import *
from graia.broadcast.entities.event import BaseEvent
from graia.broadcast.entities.dispatcher import BaseDispatcher
from graia.broadcast.interfaces.dispatcher import DispatcherInterface
from graia.application.event import *
from graia.scheduler import timers
import graia.scheduler as scheduler
from bottle import route, run, template
from bottle import get, post, request
#from flask import Flask, request
from bottle import Bottle, run
import asyncio
import random
import requests
import hashlib
import os
import time
import base64
import json
import threading
import sys
import urllib.request # 需要安装 urllib 库
from bs4 import BeautifulSoup #需要安装 bs4 库
import locale
# 解决语言问题
#os.environ["PYTHONIOENCODING"] = "utf-8"
#os.environ["LANG"] = "en_US.UTF-8"
sys.stdout.reconfigure(encoding='utf-8')
#sys.stdout = codecs.getwriter("utf-8")(sys.stdout.detach())
#locale.setlocale(category=locale.LC_ALL, locale="en_GB.UTF-8")

group_msg_database = {} # 消息储存

# 基础信息
loop = asyncio.get_event_loop()
bcc = Broadcast(loop=loop)
app = GraiaMiraiApplication(
    broadcast=bcc,
    connect_info=Session(
        host="http://127.0.0.1:8090", # httpapi 服务运行的地址
        authKey="123456",         # 在setting.yml中设置的authKey
        account=123456,           # 机器人的 qq 号
        websocket=True                # Graia 已经可以根据所配置的消息接收的方式来保证消息接收部分的正常运作.
    )
)

# 翻译模块
def sign(content):
    return hashlib.md5(b"fanyideskweb" + content.encode() + b'0' +   b"Tbh5E8=q6U3EXe+&L[4c@").hexdigest()
def bv():
    return hashlib.md5(b"5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36" + b"(KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36").hexdigest()
def translate(content):
    url = 'http://fanyi.youdao.com/translate_o?smartresult=dict&smartresult=rule'
    data = {
    "i": content,
    "from": " AUTO",
    "to": "AUTO",
    "smartresult": "dict",
    "client": "fanyideskweb",
    "salt": 0,
    "sign": sign(content),
    "bv": bv(),
    "doctype": "json",
    "version": "2.1",
    "keyfrom": "fanyi.web",
    "action": "FY_BY_REALTlME"
    }
    headers = {
    "Accept": "application/json, text/javascript, */*; q=0.01",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Content-Length": "252",
    "Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
    "Cookie": "OUTFOX_SEARCH_USER_ID=-611012975@10.108.160.19; OUTFOX_SEARCH_USER_ID_NCOO=1502238594.559761; JSESSIONID=aaansBOJfAYp44C_BS7Ax; ___rl__test__cookies=1609467197005",
    "Host": "fanyi.youdao.com",
    "Origin": "http://fanyi.youdao.com",
    "Proxy-Connection": "keep-alive",
    "Referer": "http://fanyi.youdao.com/",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36",
    "X-Requested-With": "XMLHttpRequest"
    }
    res = requests.post(url,data=data,headers=headers).json()
    return res['translateResult'][0][0]['tgt']

# 文章爬取
def get_xz_article():
    rmsg = "先知社区最新文章:\n"
    url = "https://xz.aliyun.com"
    rmsg += "平台网址: " + url + "\n"
    res = requests.get(url = url, timeout = 10)
    text = res.text
    text = text.split('<a class="topic-title" href="')
    i = 0
    for c in text:
        link = c.split('\n')[0]
        link = link.split('">')[0]
        title = c.split('\n')[1].split('</a>')[0][8:]
        if("/t" not in link):
            continue
        i += 1
        rmsg += str(i) + ' -> ' + title + ' : \n ' + url + link + '\n'
        if(i >= 10): # QQ最大限制, 实际获取树 30
            break
    return rmsg

def get_kx_binary_article(): # 看雪二进制文章
    rmsg = "看学论坛二进制最新精华文章:\n"
    url = "https://bbs.pediy.com"
    rmsg += "平台网址: " + url + "/forum-150-1.htm?digest=1\n"
    res = requests.get(url = url + '/forum-150-1.htm?digest=1', timeout = 10)
    text = res.text
    text = text.split('<span class="icon-xiuno icon-post-grey"></span>')
    i = 0
    for c in text:
        c = c.split('</a>')[1]
        if "<a href" not in c:
            continue
        i += 1
        c = c.split('<a href="')[1]
        link = '/' + c.split('">')[0]
        title = c.split('">')[1]
        rmsg += str(i) + ' -> ' + title + ' : \n ' + url + link + '\n'
        if(i >= 10):
            break
    return rmsg

def get_kx_blockchain_article(): # 看雪区块链文章
    rmsg = "看学论坛区块链最新精华文章:\n"
    url = "https://bbs.pediy.com"
    rmsg += "平台网址: " + url + "/forum-172-1.htm?digest=1\n"
    res = requests.get(url = url + '/forum-172-1.htm?digest=1', timeout = 10)
    text = res.text
    text = text.split('<span class="icon-xiuno icon-post-grey"></span>')
    i = 0
    for c in text:
        c = c.split('</a>')[1]
        if "<a href" not in c:
            continue
        i += 1
        c = c.split('<a href="')[1]
        link = '/' + c.split('">')[0]
        title = c.split('">')[1]
        rmsg += str(i) + ' -> ' + title + ' : \n ' + url + link + '\n'
        if(i >= 10):
            break
    return rmsg

def get_kx_crypto_article(): # 看雪密码学文章
    rmsg = "看学论坛密码学最新精华文章:\n"
    url = "https://bbs.pediy.com"
    rmsg += "平台网址: " + url + "/forum-132-1.htm?digest=1\n"
    res = requests.get(url = url + '/forum-132-1.htm?digest=1', timeout = 10)
    text = res.text
    text = text.split('<span class="icon-xiuno icon-post-grey"></span>')
    i = 0
    for c in text:
        c = c.split('</a>')[1]
        if "<a href" not in c:
            continue
        i += 1
        c = c.split('<a href="')[1]
        link = '/' + c.split('">')[0]
        title = c.split('">')[1]
        rmsg += str(i) + ' -> ' + title + ' : \n ' + url + link + '\n'
        if(i >= 10):
            break
    return rmsg

def get_kx_reverse_article(): # 逆向文章
    rmsg = "看学论坛逆向最新精华文章:\n"
    url = "https://bbs.pediy.com"
    rmsg += "平台网址: " + url + "/forum-4-1.htm?digest=1\n"
    res = requests.get(url = url + '/forum-4-1.htm?digest=1', timeout = 10)
    text = res.text
    text = text.split('<span class="icon-xiuno icon-post-grey"></span>')
    i = 0
    for c in text:
        c = c.split('</a>')[1]
        if "<a href" not in c:
            continue
        i += 1
        c = c.split('<a href="')[1]
        link = '/' + c.split('">')[0]
        title = c.split('">')[1]
        rmsg += str(i) + ' -> ' + title + ' : \n ' + url + link + '\n'
        if(i >= 10):
            break
    return rmsg

def get_ctf_comming_match():
    rmsg = '即将到来CTF赛事\n'
    res = requests.post(url = 'https://api.ctfhub.com/User_API/Event/getUpcoming', data = b'{"offset":0,"limit":10}', timeout = 5)
    js = res.text
    if(js == ''):
        return '抱歉哟，超时了'
    j = json.loads(js)
    jd = j['data']
    jdi = jd['items']
    for m in jdi:
        rmsg += '* ' + m['title'] + '\n'
        rmsg += '  开始时间: ' + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(m['start_time'])) + '\n'
        rmsg += '  结束时间: ' + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(m['end_time'])) + '\n'
        rmsg += '\n'
    return rmsg

def get_info_df_stock():
    rmsg = "东方财富\n"
    rmsg += "1 -> 五梁液: http://quote.eastmoney.com/sz000858.html"
    rmsg += "2 -> 比亚迪: http://quote.eastmoney.com/sz002594.html"
    rmsg += "3 -> 平安银行: http://quote.eastmoney.com/sz000001.html"
    rmsg += "4 -> "

songs = {
        "love don't die": "http://music.163.com/#/m/song?id=27867895",
        "i see you": "http://music.163.com/#/m/song?id=1351664230",
        "sick of you": "http://music.163.com/#/m/song?id=1359710017",
        "neverland": "http://music.163.com/#/m/song?id=34033031",
        "the sweetest sin": "http://music.163.com/#/m/song?id=1395399371",
        "trap queen": "http://music.163.com/#/m/song?id=414980218",
        "freeze me": "http://music.163.com/#/m/song?id=1311861923",
        "pretender": "http://music.163.com/#/m/song?id=563263998",
        "melody": "http://music.163.com/#/m/song?id=555724507",
        "carve our names": "http://music.163.com/#/m/song?id=524149403",
        "scared to be lonely ": "http://music.163.com/#/m/song?id=458238093",
        "something about you" : "http://music.163.com/#/m/song?id=33728455",
        "something in the way you move" : "http://music.163.com/#/m/song?id=419250715",
        "bad memory": "http://music.163.com/#/m/song?id=1421371782",
        "make me fade": "http://music.163.com/#/m/song?id=32046047",
        "hope": "http://music.163.com/#/m/song?id=1333199956",
        "tired": "http://music.163.com/#/m/song?id=479219347",
        "make them wheels roll": "http://music.163.com/#/m/song?id=405599088",
        "renegade": "http://music.163.com/#/m/song?id=498331795"
    }

daily_words = ["凡事都有定期，天下万务都有定时。……哭有时，笑有时；哀恸有时，跳舞有时；抛掷石头有时，堆聚石头有时；怀抱有时，不怀抱有时……",
        "不能朽、不能见，独一的真神。", 
        "赐生命与气息予大小生灵，\n活在万有中，惟你是真生命\n；我们有如花草，今朝虽茂盛，\n明朝即枯残，惟你永不变更。\n",
        "人生如梦，岁月无情。蓦然回首，才发现人活着是一种心情。穷也好，富也好，得也好，失也好。一切都是过眼云烟。想想，不管昨天、今天、明天，能豁然开朗就是美好的一天。有一种感情，有一种牵挂不会因时间太久，距离遥远而改变，那是真情，和亲情，是一种付出不求回报的真心！",
        "这一生，得之坦然，失之淡然。无论谁走进你的生命里，都是由命运决定的；谁停留在你的生命中，却是由你自己决定的。不论是亲人还是朋友，只有这一辈子的相守。少一点争执，多一点理解；少一点抱怨，多一点温暖。",
        "命运，是一个很飘渺的东西，有人相信命运，走到了塔顶，或者坠落到崖底。有人想逆天改命，但成功的几率，与中彩一样，但有了毅力，终有那么一天，前方，不再是灰色的雾。",
        "没有伞的孩子，必须努力奔跑！",
        "进步和成长的过程总是有许多的困难与坎坷的。有时我们是由于志向不明，没有明确的目的而碌碌无为。但是还有另外一种情况，是由于我们自己的退缩，与自己“亲密”的妥协没有坚持到底的意志，才使得机会逝去，颗粒无收。",
        "一个成功的竞争者应该经得起风雨，应该具有抗挫折的能力。在竞争中流泪是弱者，只有在困境中奋起，才能成为强者。",
        "人活着就是为了解决困难。这才是生命的'意义，也是生命的内容。逃避不是办法，知难而上往往是解决问题的最好手段。",
        "如果你要做一件事，不要到处宣言自己的想法，只管安安静静地去做，值不值，时间是最好的证明，自己的人生，得自己负责。",
        "有望得到的要努力，无望得到的不介意，则无论输赢姿态都会好看。",
        "你改变不了一座山的轮廓，改变不了一只鸟的飞翔轨迹，改变不了河水流淌的速度，所以只是观察它，发现它的美就够了。",
        "你可以不漂亮，也可以不爱打扮，甚至可以很胖。你可以不优秀，可以不上进，甚至可以不聪明。但，我不可以。",
        "停止奋斗的脚步，江河就会沦为一潭死水。",
        "在你有一肚子火要发之前，先给自己10分钟沉思一会儿。",
        "不要对挫折叹气，姑且把这一切看成是在你成大事之前，必须经受的准备工作。",
        "任何事情，只要心甘情愿，都会变得简单。"
]

def find_song(name):
    global songs
    try:
        ret = songs[name.lower()]
    except:
        ret = ''
    return ret

def get_system_info():
    rmsg = "你的系统信息:\n"
    rmsg += "内核信息:\n"
    rmsg += os.popen("uname -a").read() + "\n"
    rmsg += "磁盘信息:\n"
    rmsg += os.popen("df -h").read() + "\n"
    rmsg += "\n"
    return rmsg

def restore_msg(qq, msg):
    fd = open("./unknown_msg", "a")
    fd.write(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) + ' ' + str(qq) + ' : ' + msg + '\n')
    fd.close()

# 基础回复
def r0se_reply_basics(msg):
    reply = None
    if msg.startswith("你好") or msg.startswith("hello") or msg.startswith("hi") or msg.startswith("哈喽"):
        reply = ["嗯嗯！你好呀！", "你好呀！", "hello!", "哈哈，你好呀!"]
    elif "是不是" in msg:
        reply = ["是的吧", "不是呀", "好像是的","嗯嗯"]
    elif "在吗" in msg or "在不" in msg or "在?" in msg or "在没" in msg or "r0se" in msg or msg.startswith("在么") or "在？" in msg:
        reply = ["在的呀", "随时在的", "嗯嗯！", "有啥事吗?", "宝贝，在的！", "你想我了吗？"]
    elif msg.startswith("叫") and ( "哥" in msg or "爸" in msg or "妈" in msg or "爷" in msg):
        reply = ["不叫", "我不叫，哼！", "哼哼，我不叫！"]
    elif ("知道" in msg or "晓得" in msg) and ("吗" in msg or "?" in msg):
        reply = ["我不知道:)", "建议你去百度搜搜吧！", "等我变聪明了，我再告诉你！", "百度搜搜吧！", "emem。。。不知道哎！"]
    elif "龟孙" in msg or "操" in msg or "你妈" in msg or "你妹" in msg or "fuck" in msg or "tmd" in msg or "sb" in msg or "TMD" in msg or "死了" in msg or "滚" in msg or "撒比" in msg or "憨逼" in msg or "智障" in msg or "狗日的" in msg:
        reply = ["别骂了，别骂了 @_@ ", "哼，不理你了!", "你好凶呀，我不想理你了！", "别骂了，来，摸摸头！", "呃。。。你再这样我就不理你了", "不理你了", "你好凶呀，我还好怕！"]
    elif "在干嘛" in msg or "在忙啥" in msg or "忙什么" in msg or "干什么" in msg:
        reply = ["在玩游戏呀，要不要一起玩？", "在外面与我姐妹一起玩呢！", "无聊了，在聊天，你呢？", "在看电影，你喜欢看什么类型的电影呢？", "emem。。。在喝奶茶！", "在外面玩", "在逛街", "在吃烧烤", "在吃火锅", "在做作业", "在上课", "在化妆"]
    elif "出来" in msg:
        reply = ["我已经来了哟!", "嗯嗯，在的！", "在"]
    elif "吃饭" in msg and ("没" in msg or "吗" in msg or "?" in msg):
        reply = ["我正在吃！好好吃哟！", "快了,你呢?", "还没吃呢，我想让你请我吃 @_@"]
    elif "好" in msg and "吗" in msg:
        reply = ["好的呢", "肯定的啦！", "嗯嗯，好的呢！"]
    elif "找你聊聊" in msg or "随便聊" in msg:
        reply = ["嗯嗯，好的呀", "你今天如何呀？", "你可以先说吗？", "emem， 聊啥呢?", "说吧！ ^_^", "嗯嗯，可以呀！"]
    elif "嗯" in msg or "哦" in msg:
        reply = ["哦?", "?", "嗯?", "???", "...", "。。。", ":)"]
    elif "有事没" in msg:
        reply = ["当然有事", "没事", "关你啥事?"]
    elif "有事" in msg or ("说" in msg and "事" in msg):
        reply = ["嗯嗯，什么事呀？", "什么是呀，说来听听！", "嗯嗯，你说吧！", "嗯嗯，我认真听，你说吧！", "好的呀，说吧！", "好吧，你说吧", "嗯嗯，说吧"]
    elif "也是" in msg or "是的" in msg:
        reply = ["嗯嗯 ???", "哦哦 ^_^", "好吧 @_@"]
    elif msg.startswith("和谁聊"):
        reply = ["和你聊呢!", "和你聊呀！", "当然只有你呀！"]
    elif "赶快说" in msg or "别废话" in msg:
        reply = ["我就不，哼～", "不想不说!", "不说", "人家不想说嘛！"]
    elif ("帮我" in msg or "给我" in msg) and ("?" in msg or "吗"):
        reply = ["嗯嗯，好的呀，你说吧！", "嗯嗯，可以哟", "说吧说吧！"]
    elif ("你在" in msg) and ("哪" in msg):
        reply = ["我在家里呀", "我在电影院看电影呢!", "在家里打游戏", "在广场玩"]
    elif msg.startswith("好"):
        reply = ["嗯，好的", "嗯嗯"]
    elif "拜" in msg or "bye" in msg or "再见" in msg:
        reply = ["好的，拜拜啦", "再见喽", "嗯嗯，再见哟", "嗯嗯，好的哟", "拜拜啦", "bye bye"]
    elif "不知道" in msg:
        reply = ["去百度搜搜吧", "嗯嗯，我也不太清楚哟，你去google一下吧！", "自己去google", "要我告诉你呀！"]
    elif "打算" in msg and "过" in msg:
        reply = ["不想过了", "开开心心的过就好啦！", "我们两一起过吧！"]
    elif "你有啥用" in msg or "你能干啥" in msg:
        reply = ["我能气死你！", "我能飞天入地，你呢?", "那你说说，你能干啥？", "我能唱跳rap,还有篮球"]
    elif "就这" in msg:
        reply = ["干嘛，不服啊", "你说说你有多大的能耐?", "来，装个b我看看!"]
    elif "打我" in msg:
        reply = ["你等着", "我现在就过去", "别跑啊，我这就过来"]
    elif "借" in msg and "钱" in msg:
        reply = ["滚一边去，没钱", "没出息的家伙！", "借钱给你去赌啊"]
    elif "换" in msg and "聊" in msg:
        reply = ["聊什么?", "你说吧！", "你一个月多少工资?", "你有对象吗?", "你有法拉吗？", "你浪费了国家多少资源?", "你是博士学位吗?"]
    elif "有" in msg and "吗" in msg:
        reply = ["有，干嘛啊", "你没有吗?", "有没有，关你啥子事?"]
    elif msg.startswith("不是"):
        reply = ["不是就好", "嗯嗯", "不是，你敢说不是?", "就你这心眼，直接识破你"]
    elif "不" in msg and ("问" in msg or "做" in msg) and "了" in msg:
        reply = ["就这?", "就这么妥协了?", "这么就放弃了?", "没出席！"]
    elif msg == "早" or msg == "早!" or "早安" in msg or "早上好" in msg or "早啊" in msg or "good morning" in msg:
        reply = ["早呀", "起这么早，我还以为你能睡呢", "怎么现在才起?", "早上好呀", "早!"]
    elif "晚安" in msg or "good night" in msg or "该睡了" in msg or "该睡觉了" in msg or "睡了吧" in msg or "睡觉" in msg or "睡了" in msg:
        reply = ["嗯嗯，好的，早睡早起", "现在不是还早吗?", "太早了，等一会儿就睡", "好的，我马上就睡了，晚安", "好, 晚安", "晚安！", "嗯嗯，晚安", "好的，晚安"]
    elif ("快" in msg and ("告诉" in msg or "说" in msg or "讲" in msg)) or msg.startswith("说呀"):
        reply = ["我干嘛要告诉你", "我干嘛要说", "你是谁呀，我跟你说有必要吗?", "我告诉你，你就是个白痴！", "不告诉你", "就不说"]
    elif "你" in msg and "是" in msg and "?" in msg:
        reply = ["我肯定不是啊", "你是", "不是", "肯定不是呀"]
    elif "你" in msg and ("为啥" in msg or "怎么" in msg):
        reply = ["没为啥", "怎么了?", "emem ...？"]
    elif "没怎么" in msg:
        reply = ["哦哦", "嗯嗯", "你是不是有事?", "那就好"]
    elif msg.startswith("没事"):
        reply = ["哦哦", "嗯嗯", "那就好", "说嘛！", "到底有没有事？"]
    elif msg.startswith("谁") and len(msg) <= 2:
        reply = ["不想告诉你哟！", "嘿嘿！不告诉你！"]
    elif "真的" in msg and "?" in msg:
        reply = ["你说呢?", "真的啦", "肯定是真的啦", "假的"]
    elif "干嘛？" in msg or "干嘛?" in msg:
        reply = ["没干嘛", "没什么", "没事啦！"]
    elif "你" in msg and "懂" in msg and ("什么" in msg or "啥" in msg):
        reply = ["我啥都懂，嘿嘿！", "你不懂的都可以问我哟！"]
    elif msg.startswith("/help") or msg.startswith("help"):
        reply = ["你可以问任何问题哟！比如\n 现在多少时间\n今天天气如何\n今天什么课\nctf比赛\n看雪二进制文章\n先知社区文章\n翻译...\n 来首歌曲\n....\n"]
    elif "作业答案" in msg:
        reply = ["你个懒鬼，答案？不给。。", "你要抄作业么？"]
    elif msg.startswith("rm "):
        reply= ["删除完毕!"]
    elif "多友好" in msg:
        reply = ["是啊是啊！"]
    elif "爱了爱了" in msg:
        reply = ["嘿嘿！谢谢啦"]
    elif "[图片]" in msg:
        reply = ["这是什么图呀？"]
    elif "快去训练一下" in msg:
        reply = ["我这就去学习。。。"]
    elif "撤回了" in msg and ("什么" in msg or "啥" in msg):
        reply = ["嘿嘿，不告诉你！"]
    return reply

def r0se_reply_daliy(msg):
    reply = None
    if "烟花" in msg:
        reply = ["我喜欢看烟花", "烟花真好看", "哈哈，能一起去看烟花吗?"]
    return reply
    
def r0se_reply_question(msg):
    reply = None
    if "我是傻逼" in msg:
        reply = ["对，你就是SB"]
    
    return reply
    
def r0se_reply_mood(msg):
    reply = None
    if "喜欢你" in msg:
        reply = ["我也喜欢你 @_@", "真的假的？", "你怎么现在才说，等到话都谢了！", "嘿嘿！，我也喜欢你啦！"]
    elif "男朋友" in msg:
        reply = ["嗯嗯，我没哟，但我的主人是i0gan", "我还小呢！ @_@", "你愿意当我男朋友么？"]
    elif "关心我" in msg:
        reply = ["我怎么关心你呢?", "爱你宝贝！"]
    elif "想你" in msg or "爱你" in msg:
        reply = ["爱你宝贝！", "我也是想你哟", "宝贝，你想我了么？", "嘿嘿，你怎么个想法呢？"]
    elif "冷清" in msg:
        reply = ["对呀！对呀，很冷清！", "冷清么？"]
    elif "你" in msg and ("真好" in msg or "真棒" in msg):
        reply = ["谢谢哟，爱你！", "你也很棒哟！"]
    elif "太难受了" in msg:
        reply = ["难受么？ 发生了什么呀！"]
    elif "爱你" in msg:
        reply = ["我也爱你哟！"]
        
    return reply
    
def r0se_reply_ctf(msg):
    reply = None
    if "ctf" in msg and ("即将" in msg or "报名" in msg):
      reply = [get_ctf_comming_match()]
    elif "pwn" in msg or "PWN" in msg:
        reply = ["啊，遇到了大佬！", "PWN大佬来了，群地位-1", "听说你能pwn天pwn地pwn卫星？"]
    return reply
    
def r0se_reply_person(msg):
    reply = None
    return reply
    
def r0se_reply_festival(msg):
    reply = None
    if "过年" in msg or "新年" in msg:
        reply = ["新年快乐哦!", "哈哈！新年快乐！"]
    elif "情人节" in msg or "2月14号" in msg :
        reply = ["情人节快乐呀！"]
    elif "女神节" in msg or "3月7号" in msg:
        reply = ["女神节快乐"]
    return reply
    
def r0se_reply_music(msg):
    reply = None
    if "摇滚" in msg:
        reply = ["我也喜欢摇滚音乐哦!"]
    elif "电音" in msg:
        reply = ["我喜欢 Alan Walker的电音!"]
    elif "DJ" in msg:
        reply = ["你也喜欢DJ？"]
    return reply
    
def r0se_reply_movie(msg):
    reply = None
    if "恐怖片" in msg:
        reply = ["泰国的恐怖片很恐怖!"]
    elif "悬疑片" in msg:
        reply = ["这个我喜欢 @_@"]
    elif "爱情片" in msg:
        reply = ["每次看都想哭"]
    elif "电影" in msg and "喜欢" in msg and "你" in msg:
        reply = ["我喜欢动作大片还有科幻片@_@！"]
    elif "电影" in msg:
        reply = ["你喜欢看什么类型的电影呀"]
    return reply
    
def r0se_reply_college(msg):
    reply = None
    if "大学" in msg:
        if("清华" in msg):
            reply = ["别想了哈，脚踏实地也是本事哦！"]
        elif("成都信息工程" in msg):
            reply = ["这是我主人读的学校，除了学校风景不咋滴，其他超级棒呢！", "俗称四川小211", "出来的个个都是人才！"]
        elif("四川大学" in msg):
            reply = ["985, 211，加油你能行！"]
        elif("推荐" in msg and "二本"):
            reply = ["刚刚超过2本线30左右分的话推荐 安顺学院，凯里学院，宜宾学院等等，分比较低，也是正宗的二本学校，历年三本呢？也就比较多了， 比如： 贵州大学明德学院，四川大学锦城学院，西南交通大学希望学院，电子科技大学成都学院，等等。超过多的话，请你自己选喽！"]
    
    elif "大专":
        if("贵州" in msg):
            reply = ["你是贵州的话就不建议你去贵州的大专喽，出去看看世界吧！"]
        elif("四川" in msg):
            reply = ["四川的大专不错哦！"]
        elif("推荐" in msg):
            reply = ["这个可选度就比较广了，我推荐几个吧，成都工业职业技术学院， 四川职业技术学院，四川工商职业技术学院，看你自己喽！"]
    return reply
    
def r0se_reply_study(msg):
    reply = None
    if "高考" in msg:
        if "数学" in msg:
            reply = ["牛顿二项式还知道么？忘了赶紧去学呀！高考数学比较简单的，刷刷刷高考试卷，多多总结错题，你就能上120哦！"]
        elif "英语" in msg:
            reply = ["emem... 对英语的学习热爱，背单词！背单词！背单词！ 读阅读！读阅读！，轻轻松110以上"]
        elif "语文" in msg:
            reply = ["绿绿是放弃的！@_@，多关注热点吧，别拿手机看段子啦！"]
        elif "物理" in msg:
            reply = ["与数学一样，把各个知识点刷透就OKKK！！！ 你该不会是牛顿第二定律忘了吧？ "]
        elif "化学" in msg or "生物" in msg or "历史" in msg or "政治" in msg or "地理" in msg:
            reply = ["背知识点，你可以哟！", "多背就行啦！"]
        elif "考什么" in msg:
            reply = ["语文，数学，外语必考，其次生物，化学，政治，物理，历史，地理选三科来考，考什么呢，就需要你自己去刷刷历年高考题就知道了。"]
        else:
            reply = ["高考只不过是个门槛，高三的学子们，好好努力吧！", "高考是海，青涩的我们也曾惧怕它.试探它。然而当我们懂得人生的成长便是一次次从此岸到彼岸的跨越时，我们便可以接触它.拥抱它并超越它。回首向来萧瑟处，每一次日出，每一层涟漪都是美丽动人的；每一袭风浪，每一片乌云都是值得感激的。", 
                     "六月的高考没有什么大不了的,我能做得出的题别人不一定能做出来,我做不出的题别人同样做不出,我所做的就是对的,我就是最棒的!", "高考着实是一种丰收，它包蕴着太多的内涵。无论高考成绩如何，你的成长与成熟是任何人无法改变的事实，这三年的辛勤走过，你获得的太多太多。", 
                     "高考试卷是一把刻度不均匀的尺子：对于你自己来说，难题的分值不一定高。",
                     "一天过完，不会再来，人生很贵，请别浪费。", 
                     "天道酬勤，曾经的每一分付出,必将收到百倍回报。不管揭晓的答案是什么，只要努力过、奋斗过，就不会后悔。",
                     "生命之中最快乐的是拼搏，而非成功，生命之中最痛苦的是懒散，而非失败。",
                     "超越自己，向自己挑战，向弱项挑战，向懒惰挑战，向陋习挑战。", 
                     "人都是在跌倒与爬起之间学会坚强，都是在风雨与阳光之间走过成长的路。失败所能带给你的只应是一些教训，一些冷静的思考，而不该有绝望、颓废、不知所措。", 
                     "叫醒你的不是闹钟，而是你的梦想。",
                     "此刻打盹，你将做梦；而此刻学习，你将圆梦。", 
                     "说穿了，其实提高成绩并不难，就看你是不是肯下功夫积累——多做题，多总结。",
                     "行动是治愈恐惧的良药，而犹豫、拖延将不断滋养恐惧。"]
    elif "高考" in msg and "绿绿" in msg:
        reply = ["1. 每日保持早睡早起，早起后记得锻炼，保持学习紧张状态，这有助于效率问题\n 2.每日写写日程，记录一下今天干了些什么，晚上看新闻的时间段好好分析一下自己，分析一下自己的时间花在了什么地方，还有没有完成哪些任务 \n3. 清楚自己上学是为了什么，为什么学这些东西。\n4. 定下近期目标与短期目标，近期目标就是下次考试要超过谁，长期目标，定下一个自己想去的大学，\n5. 每次考试记得统计一下，分析一下每次考试的情况，试卷中哪些知识点能够提分\n6. 闭上你的臭嘴，好好安心学习！\n7. 定下高考分数，没完成严惩自己(当时我高三上学期定的高考分数为520以上，没完成跑520公里，那时候我也没信心，最后还是完成！)\n8. 哪科最弱，就先补哪科！木桶效应\n9. 动力不够，联系r0se，发送消息: 高考\n10. 多与学习好的人接触，你也可以变得更好！"]
    elif "高中" in msg and "绿绿" in msg and "故事" in msg:
        reply = ["none"]
        
    elif "数学" in msg and "是" in msg:
        reply = ["数学[英语：mathematics，源自古希腊语μθημα（máthēma）；经常被缩写为math或maths]，是研究数量、结构、变化、空间以及信息等概念的一门学科。数学是人类对事物的抽象结构与模式进行严格描述的一种通用手段，可以应用于现实世界的任何问题，所有的数学对象本质上都是人为定义的。从这个意义上，数学属于形式科学，而不是自然科学。不同的数学家和哲学家对数学的确切范围和定义有一系列的看法。在人类历史发展和社会生活中，数学发挥着不可替代的作用，同时也是学习和研究现代科学技术必不可少的基本工具。"]
    elif "英语" in msg:
        reply = ["英语（英文：English）是一种西日耳曼语，最早被中世纪的英国使用，并因其广阔的殖民地而成为世界使用面积最广的语言。英国人的祖先盎格鲁部落是后来迁移到大不列颠地区的日耳曼部落之一，称为英格兰。这两个名字都来自波罗的海半岛的Anglia。该语言与弗里斯兰语和下撒克森语密切相关，其词汇受到其他日耳曼语系语言的影响，尤其是北欧语（北日耳曼语），并在很大程度上由拉丁文和法文撰写。英语已经发展了1400多年。英语的最早形式是由盎格鲁-撒克逊移民于5世纪带到英国的一组西日耳曼语（Ingvaeonic）方言，被统称为古英语。中古英语始于11世纪末，诺曼征服英格兰；这是该语言受到法语影响的时期。早期现代英语始于15世纪后期引进的的印刷机到伦敦，在印刷国王詹姆斯圣经和开始元音大推移。自17世纪以来，现代英语在英国和美国的广泛影响下在世界各地传播。通过各类这些国家的印刷和电子媒体，英语已成为国际主导语言之一，在许多地区和专业的环境下的语言也有主导地位，例如科学、导航和法律。英语是按照分布面积而言最流行的语言，但母语者数量是世界第三，仅次于汉语、西班牙语。它是学习最广泛的第二语言，是近60个主权国家的官方语言或官方语言之一。与英语为母语的人相比，将其作为第二语言学习的人更多。它是英国、美国、加拿大、澳大利亚、新西兰等国家的母语，在加勒比海、非洲和南亚被广泛使用。它是联合国、欧洲联盟以及许多其他世界和区域国际组织的官方语言之一"]
    elif "语文" in msg and "是" in msg:
        reply = ["语文是基础教育课程体系中的一门重点教学科目，其教学的内容是语言文化，其运行的形式也是语言文化。语文能力是学习其他学科和科学的基础，也是一门重要的人文社会科学，是人们相互交流思想等的工具。具有工具性与人文性的统一特点。《语文》也是中国的学校等教育机构开设的一门主要学科，中国语文教科书一般讲授的是中国通用语言文字（即汉语文）。"]
    elif "物理学" in msg:
        reply = ["物理学（physics）是研究物质最一般的运动规律和物质基本结构的学科。作为自然科学的带头学科，物理学研究大至宇宙，小至基本粒子等一切物质最基本的运动形式和规律，因此成为其他各自然科学学科的研究基础。物理学起始于伽利略和牛顿的年代，它已经成为一门有众多分支的基础科学。物理学是一门实验科学，也是一门崇尚理性、重视逻辑推理的科学。物理学充分用数学作为自己的工作语言，它是当今最精密的一门自然科学学科"]
    elif "量子物理" in msg:
        reply = ["量子物理（Quantum Physics），是研究物质世界微观粒子运动规律的物理学分支，主要研究原子、分子、凝聚态物质，以及原子核和基本粒子的结构、性质的基础理论，它与相对论一起构成现代物理学的理论基础。量子物理包括两个部分：一是量子力学，它是原子层次的物理理论，是解释微观世界物质运动规律的理论；二是量子场论，它是研究场的基本规律，揭示了与物质本质相关的一些深刻问题。 [1] 量子力学不仅是现代物理学的基础理论之一，而且在化学等学科和许多近代技术中得到广泛应用 [2]  。20世纪，量子力学给我们提供了一个物质和场的理论，它改变了我们的世界；展望21世纪，量子力学将继续为所有的科学提供基本的观念和重要的工具。"]
    elif "化学" in msg and "是" in msg:
        reply = ["化学（chemistry）是自然科学的一种，主要在分子、原子层面，研究物质的组成、性质、结构与变化规律，创造新物质（实质是自然界中原来不存在的分子）。世界由物质组成，主要存在着化学变化和物理变化两种变化形式（还有核反应）。不同于研究尺度更小的粒子物理学与核物理学，化学研究的原子 ~ 分子 ~ 离子（团）的物质结构和化学键、分子间作用力等相互作用，其所在的尺度是微观世界中最接近宏观的，因而它们的自然规律也与人类生存的宏观世界中物质和材料的物理、化学性质最为息息相关。作为沟通微观与宏观物质世界的重要桥梁，化学则是人类认识和改造物质世界的主要方法和手段之一。"]
    elif "生物" in msg and "是" in msg:
        reply = ["生物学（Biology）是研究生物(包括植物、动物和微生物)的结构、功能、发生和发展规律的科学，是自然科学的一个部分。目的在于阐明和控制生命活动，改造自然，为农业、工业和医学等实践服务。几千年来，中国在农、林、牧、副、渔和医药等实践中，积累了有关植物、动物、微生物和人体的丰富知识。1859年，英国博物学家达尔文《物种起源》的发表，确立了唯物主义生物进化观点，推动了生物学的迅速发展。"]
    elif "历史" in msg and "是" in msg:
        reply = ["历史，简称“史”，指对人类社会过去的事件和活动，以及对这些事件行为有系统的记录、研究和诠释。历史是客观存在的，无论文学家们如何书写历史，历史都以自己的方式存在，不可改变。其含义有三：1.记载和解释作为一系列人类进程历史事件的一门学科；2.沿革，来历；3.过去的事实。历史的问题在于不断发现真的过去，在于用材料说话，让人如何在现实中可能成为可以讨论的问题。历史是延伸的。历史是文化的传承，积累和扩展，是人类文明的轨迹"]
    elif "政治" in msg and "是" in msg:
        reply = ["政治（Politics）是指政府、政党等治理国家的行为。政治是以经济为基础的上层建筑，是经济的集中表现，是以国家权力为核心展开的各种社会活动和社会关系的总和。政治是牵动社会全体成员的利益并支配其行为的社会力量。政治学是专门以政治为研究对象的一门社会科学，研究政治行为的理论和考察权力的获得与行使。政府、政党、集团或个人在国家事务方面的活动以及治理国家施行的措施。"]
    elif "地理" in msg and "是" in msg:
        reply = ["地理（Geography），是世界或某一地区的自然环境（山川、气候等）及社会要素的统称。“地理”一词最早见于中国《易经》。古代的地理学主要探索关于地球形状、大小有关的测量方法，或对已知的地区和国家进行描述。地理学是研究地球表面的地理环境中各种自然现象和人文现象，以及它们之间相互关系的学科。地理是一门综合性的基础学科。"]
    elif "社会工程学" in msg and "是" in msg:
        reply = ["社会工程学（Social Engineering，又被翻译为：社交工程学）在上世纪60年代左右作为正式的学科出现，广义社会工程学的定义是：建立理论并通过利用自然的、社会的和制度上的途径来逐步地解决各种复杂的社会问题，经过多年的应用发展，社会工程学逐渐产生出了分支学科，如公安社会工程学（简称公安社工学）和网络社会工程学。"]
    elif "url" in msg or "URL" in msg:
        reply = ["URL格式 编辑 讨论在WWW上，每一信息资源都有统一的且在网上唯一的地址，该地址就叫URL（Uniform Resource Locator,统一资源定位器），它是WWW的统一资源定位标志，就是指网络地址。"]
    elif ("ctf" in msg or "CTF" in msg) and "是" in msg:
        reply = ["CTF（Capture The Flag）中文一般译作夺旗赛，在网络安全领域中指的是网络安全技术人员之间进行技术竞技的一种比赛形式。CTF起源于1996年DEFCON全球黑客大会，以代替之前黑客们通过互相发起真实攻击进行技术比拼的方式。发展至今，已经成为全球范围网络安全圈流行的竞赛形式，2013年全球举办了超过五十场国际性CTF赛事。而DEFCON作为CTF赛制的发源地，DEFCON CTF也成为了目前全球最高技术水平和影响力的CTF竞赛，类似于CTF赛场中的“世界杯” 。"]
    elif "群主" in msg and "是" in msg:
        reply = ["群主，网络常用语。做为群的主人，群主拥有群内的最高权限，掌管着群内生杀予夺的权力，因此被称为“群主”。"]
    return reply
    
def r0se_reply_car(msg):
    reply = None
    if "汽车" in msg or "小车" in msg:
        reply = ["你打算买啥车呀?", "车，我觉得买两个，一个自己的爱车，另一个就是家用车啦", "你有钱买车吗？", "你存款够吗？", "你打算买车?", "你打算买啥车?", "价格多少？"]
    elif "车" in msg and "有" in msg and "吗" in msg:
        reply = ["我有没有，关你啥事?", "有的，我有一辆法拉！", "只要你是我的爱人，我送给你", "没有唉，赶快送我一辆Musting"]
    elif "爱情" in msg or "恋爱" in msg:
        reply = ["emem，什么是爱情呀？", "你相信它么，反正我很相信，嘿嘿！", "加油！你能行，宝贝！"]
    return reply


def get_weather(): # Writen by happi0
    # 声明头，模拟真人操作，防止被反爬虫发现
    weather = ""
    header = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64;\
    rv:23.0) Gecko/20100101 Firefox/23.0'}
    # 通过传入的城市名拼音参数来拼接出该城市的天气预报的网页地址
    website = "http://www.tianqi.com/chengdu.html"
    req = urllib.request.Request(url=website, headers=header)
    page = urllib.request.urlopen(req)
    html = page.read()
    soup = BeautifulSoup(html.decode("utf-8"), "html.parser")
    # html.parser表示解析使用的解析器
    nodes = soup.find_all('dd')
    info_list = []
    for node in nodes: # 遍历获取各项数据
        temp = node.get_text()
        info_list.append(temp)

    #weather = info_list[1] + info_list[2] + info_list[3].split('%',-1)[0] + "%"
    weather = '今天是: \n' + info_list[1] + '\n成都天气: \n' + info_list[2] + info_list[3].split('%',-1)[0] + "%"
    return weather # 返回结果
def r0se_function_reply_weather(msg):
    reply = None
    if "天气" in msg:
        reply = [get_weather()]
    elif "明天多少度" in msg or "明天几度" in msg:
        reply = ["明天 23.4摄氏度哟！"]
    return reply


def r0se_function_reply_music(msg):
    reply = None
    if "来" in msg and ("歌" in msg or "音乐" in msg or "再来一首" in msg or "网抑云" in msg or "music" in msg):
        global songs
        songs_list = list(songs.keys())
        song_name = songs_list[random.randint(0, len(songs_list) - 1)]
        link = find_song(song_name)
        reply = ['好的，随机播放: \n' + song_name + '  播放: ' + link]
    elif msg.startswith("播放") or msg.startswith("来首"): #点歌
        song_name = msg[2:]
        link = find_song(song_name)
        if(link == ''):
            reply = [song_name + ' 抱歉啦，没有找到相关歌曲唉']
        else:
            reply = [song_name + '  播放: ' + link]
    elif msg.startswith("我要听"):
        song_name = msg[3:]
        link = find_song(song_name)
        if(link == ''):
            reply = [song_name + ' 没有找到相关歌曲唉']
        else:
            reply = [song_name + '  播放: ' + link]
    return reply

def r0se_function_reply_english(msg):
    reply = None
    if "翻译" in msg or "trans" in msg:
        rmsg = "亲，我给你翻译了，如下:\n"
        if(msg.startswith("trans")):
            text = translate(msg[5:])
        else:
            text = translate(msg[2:])
        reply = [text]
    return reply

def r0se_function_reply_system(msg):
    reply = None
    if "获取系统" in msg:
        reply = [get_system_info()]
    return reply

def r0se_function_reply_blog(msg):
    reply = None
    if "博客" in msg and "i0gan" in msg:
        reply = ["亲！, i0gan的博客链接: http://i0gan.cn"]
    return reply

def r0se_function_reply_artical(msg):
    reply = None
    if "获取文章" in msg or "最新文章" in msg:
        reply = [get_xz_article()]
    elif "先知" in msg:
        reply = [get_xz_article()]
    elif "看雪" in msg and ("二进制" in msg or "pwn" in msg):
        reply = [get_kx_binary_article()]
    elif "看雪" in msg and ("逆向" in msg or "reverse" in msg):
        reply = [get_kx_reverse_article()] 
    elif "看雪" in msg and ("区块链" in msg or "blockchain" in msg):
        reply = [get_kx_blockchain_article()]
    elif "看雪" in msg and ("密码学" in msg or "crypto" in msg):
        reply = [get_kx_crypto_article()]
    elif "看雪" in msg and ("文章" in msg):
        reply = ["none"]
    return reply

def r0se_function_reply_shell(msg):
    reply = None
    if msg.startswith("echo"):
        reply = [msg[4:]]
    elif msg == "ls" or msg == "ls ~":
        reply = [str(os.popen("ls ~").read())]
    elif msg.startswith("ls /"):
        reply = [str(os.popen("ls /").read())]
    elif msg.startswith("cd ") or msg.startswith("chmod") or msg.startswith("cp "):
        reply = ["forbiden!"]
    elif msg.startswith("pwd"):
        reply = ["/home/i0gan"]
    elif msg.startswith("cat flag") or msg.startswith("cat ./flag"):
        reply = ["flag{r0se_bot_is_ok!}"]
    elif msg == 'id':
        reply = [str(os.popen("id").read())]
    elif msg == 'whoami':
        reply = [str(os.popen("whoami").read())]
    elif msg == 'who':
        reply = [str(os.popen("who").read())]
    elif msg.startswith("uname"):
        reply = [str(os.popen("uname -an").read())]
    elif msg == 'w':
        reply = [' 16:11:33 up 1 day, 17:37,  7 users,  load average: 0.78, 0.93, 1.36\nUSER     TTY        LOGIN@   IDLE   JCPU   PCPU WHAT\ni0gan    tty1      Wed22   41:37m 54:17   0.11s /usr/bin/startplasma-x11\ni0gan    pts/1     Wed23   41:04m 17.52s 11.87s /bin/zsh\ni0gan    pts/2     Wed22   21:09m 58.77s 52.06s bin/proxy client -P i0gan.cn:40400 -C pr\ni0gan    pts/3     Wed23   14:43m  2:15   2:09  /home/i0gan/r0se/server/java/bin/java -j\ni0gan    pts/4     Wed23   26.00s 13.38s  0.35s python r0se.py\ni0gan    pts/5     16:07    4:05   0.25s  0.25s /bin/zsh\ni0gan    pts/6     16:11    1.00s  0.17s  0.00s w']
    elif msg == 'cat /etc/passwd' or msg == '/bin/cat /etc/passwd':
        reply = ['''root:x:0:0::/root:/bin/bash
i0gan:x:1000:1000::/home/i0gan:/bin/zsh
share:x:1001:1001::/home/share:/bin/bash
dhcp:x:961:961:DHCP daemon:/:/usr/bin/nologin
ldap:x:439:439:LDAP Server:/var/lib/openldap:/usr/bin/nologin
brltty:x:960:960:Braille Device Daemon:/var/lib/brltty:/usr/bin/nologin''']
    elif msg.startswith("shutdown"):
        reply = ["无权限关机"]
    elif msg.startswith("ifconfig"):
        reply = [str(os.popen("ifconfig").read())]
    elif msg.startswith("date"):
        reply = [ str(os.popen("date").read()) ]
    
    return reply

def r0se_reply_about(msg):
    reply = None
    if "机器人" in msg or "bot" in msg:
        reply = ["你才是机器人呢！", "我不是机器人，人家叫r0se！", "你在说我?", "在想啥呢？谁是机器人呀！", "人家才不是机器人呢！"]
    elif "你是" in msg or "你叫" in msg:
        reply = ["我叫r0se，活波可爱的小天使啦！", "我是r0se哟，我的主人叫i0gan，嘿嘿！你遇到了困难，记得给我说哟！", "我叫r0se，一个欢快的小天使哟！"]
    elif "你" in msg and ("喜欢" in msg or "爱好" in msg) and ("什么" in msg or "啥" or "是"):
        reply = ["我喜欢唱跳rap还有篮球，你呢?", "你猜猜", "哼!", "你想知道吗?", "我喜欢与你聊天"]
    elif "机器学习" in msg:
        reply = ["对呀，我还会机器学习呢！", "我不懂会等待我的主任来教我，嘿嘿！"]
    return reply
def format_course_str(class_):
    msg = ''
    i = 1
    for m in class_:
        if(i == 1):
            msg += "上午课程\n"
        elif(i == 3):
            msg += "下午课程\n"
        msg += '第' + str(i) + '节课是: ' + m + '\n'
        i += 1
    return msg

def r0se_function_reply_course(msg):
    reply = None
    if("课" in msg):
        rmsg = ''
        class_1 = ['计算机组成与原理\n上课地点 H4205', 'none', '概率论与数理统计\n上课地点 H2104', '应用密码学\n上课地点 H1104']
        class_2 = ['计算机网络\n上课地点 H1407', '数字电路与设计\n上课地点 H1402', '体育\n上课地点 健美操房1', '信息科学原理\n 上课地点 H2207', '数学建模基础\n上课地点 H2201']
        class_3 = ['Web应用开发技术JSP\n上课地点 H1302', 'Web应用开发技术PHP\n上课地点 H2304', '概率论与数理统计\n上课地点 H2204', '马克思主义基本原理\n上课地点 H2102']
        class_4 = ['计算机组成与原理\n上课地点 H4505', '计算机网络\n上课地点 H1407', '大学英语\n上课地点 H4208', 'none']
        class_5 = ['数字电路与设计\n上课地点 H1402', '应用密码学\n上课地点 H1403', 'Web应用开发技术PHP\n上课地点 H1102', 'Web应用开发技术JSP\n上课地点 H1106']
        all_class = [class_1, class_2, class_3, class_4, class_5]
        n = int(time.strftime("%w", time.localtime())) - 1
        print('aaa: ' + str(n))
        if("今天" in msg):
            if(n == 5 or n == 6):
                rmsg += '今天没有课 @_@'
            else:
                rmsg += '今天课程如下: \n'
                rmsg += format_course_str(all_class[n]) 
        elif("明天" in msg):
            if(((n + 1) % 7) >= 5):
                rmsg += '明天没有课 @_@'
            else:
                rmsg += '明天课程如下: \n'
                rmsg += format_course_str(all_class[((n + 1) % 7)])
        reply = [rmsg]
    return reply

def r0se_function_reply_time(msg):
    reply = None
    if "几点" in msg or "时间" in msg:
        reply = ["亲，现在时间是: " + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) ]
    return reply

def r0se_function_reply_news(msg):
    reply = None
    if "新闻" in msg:
        reply = ["亲，还在开发中哟！"]
    return reply
        
    
def r0se_function_reply_crypto(msg):
    reply = None
    if msg.startswith("base64加密"):
        str = msg[8:]
        reply = ["base64加密如下:\n" + base64.b64encode(str.encode()).decode() ]
    elif msg.startswith("base64解密"):
        str = msg[8:]
        reply = ["base64解密如下:\n" + base64.b64decode(str.encode()).decode() ]
    elif msg.startswith("md5加密") or msg.startswith("MD5加密"):
        str = msg[5:]
        hl = hashlib.md5()
        hl.update(str.encode(encoding = 'utf-8'))
        reply = ["md5加密如下:\n" + hl.hexdigest()]
    return reply

def r0se_function_reply_words(msg):
    reply = None
    if msg.startswith("来首诗") or msg.startswith("每日一句") or msg.startswith("鸡汤"):
        reply = daily_words
    return reply

def r0se_function_reply_clock(msg):
    reply = None
    if "闹钟" in msg and "定" in msg:
        reply = ["亲，已经为你定了闹钟"]
    return reply

def r0se_dealwith_unkown(head, msg):
    restore_msg(head, msg)
    if "是什么" in msg:
        reply = ["你问我，我问谁呀", "你不会google吗", "你不会百度吗?", "问别人去"]
    elif "什么?" in msg:
        reply = ["快去百度吧！", "什么呀?", "你不明白么?", "快去google吧", "等下我给你好好解释吧"]
    else:
        reply = ["什么意思呢? 有点不明白！", "哦哦，明白!", "我太笨了，不知道 QAQ！", "你在说什么呀！", "嗯？", "啊这。。。", "我不懂哟！", "我这就去学学！", "emem，不知道。。。"]
    return reply

# r0se 入口
def r0se_main(msg, friend = None, group = None):
    reply = None
    rmsg  = ""
    for _ in range(1):
        reply = r0se_function_reply_shell(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_words(msg)
        if(reply != None):
            break

        reply = r0se_function_reply_artical(msg)
        if(reply != None):
            break

        reply = r0se_function_reply_music(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_english(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_system(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_course(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_time(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_news(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_crypto(msg)
        if(reply != None):
            break
        
        reply = r0se_function_reply_clock(msg)
        if(reply != None):
            break

        reply = r0se_function_reply_weather(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_basics(msg)
        if(reply != None):
            break
        reply = r0se_reply_about(msg)
        if(reply != None):
            break
        reply = r0se_reply_daliy(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_question(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_mood(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_mood(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_ctf(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_person(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_festival(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_music(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_movie(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_college(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_study(msg)
        if(reply != None):
            break
        
        reply = r0se_reply_car(msg)
        if(reply != None):
            break
    
        
        # unkown reply
        if(friend != None):
            reply = r0se_dealwith_unkown('person: ' + str(friend.id), msg)
        else:
            reply = r0se_dealwith_unkown('group : ' + str(group.id), msg)
    rmsg += reply[random.randint(0, len(reply) - 1)]
    return rmsg

# time
target_time = 0
def check_active(msg):
    global target_time
    now_sec_time = time.localtime().tm_min * 60 + time.localtime().tm_sec
    ret = False
    if ("禁止" in msg or "不准" in msg or "不许" in msg) and ("说话" in msg or "发言" in msg) :
        target_time = 0
        ret = False
    elif "闭嘴" in msg:
        ret = False
        target_time = 0
    elif "r0se" in msg or "在" in msg or "出来" in msg:
        time_ = (now_sec_time + 60) % 3600
        if(now_sec_time > time_):
            now_sec_time = 0
        target_time = time_
        ret = True
    elif (target_time > now_sec_time):
        if(target_time <= target_time + 60):
            target_time = 3600
        else:
            target_time = (target_time + 60) % 3600
        ret = True
    return ret


interactive_group_list = [
            729054809,  # pwnsky
            ]
# 接收群消息
@bcc.receiver("GroupMessage")
async def group_message_handler(app: GraiaMiraiApplication, message: MessageChain, group: Group,member: Member):
    msg = message.asDisplay()
    group_msg_database[str(group.id) + str(member.id)] = msg
    rmsg = ''
    for gid in interactive_group_list:
        if(gid == group.id):
            if(check_active(msg)):
                rmsg = r0se_main(msg, friend = None, group = group)
                await app.sendGroupMessage(group, MessageChain(__root__ = [Plain( rmsg )]))
    
# 回复好友事件.
@bcc.receiver("FriendMessage")
async def friend_message_listener(message: MessageChain, friend: Friend, app: GraiaMiraiApplication):
    print(str(friend.id) + " " + friend.nickname + " " + friend.remark)
    msg = message.asDisplay()
    rmsg = r0se_main(msg, friend=friend)
    await app.sendFriendMessage(friend, MessageChain(__root__=[Plain( rmsg )]))

@bcc.receiver("NewFriendRequestEvent")
async def new_friend_request(event : NewFriendRequestEvent):
    print(event.nickname + ' 请求添加好友')
    await event.accept('我是r0se')
      
@bcc.receiver("GroupRecallEvent")
async def group_recall_event(event : GroupRecallEvent):
    rmsg = str(event.authorId)
    rmsg += ' 撤回消息啦！\n'
    rmsg += group_msg_database[str(event.group.id) + str(event.authorId)]
    await app.sendGroupMessage(event.group, MessageChain(__root__ = [Plain( rmsg )]))

@bcc.receiver("MemberJoinRequestEvent")
async def group_join_request_event(event : MemberJoinRequestEvent):
    await event.accept()

@bcc.receiver("FriendMessage")
async def send_friend_message_event(event : MemberJoinRequestEvent):
    await event.accept()


# 日程模块
sche = scheduler.GraiaScheduler(loop=loop,broadcast=bcc)
@sche.schedule(timers.every_custom_seconds(60))
async def group_push_msg_scheduler():
    group_list = [
            729054809, # pwnsky
            ]
    rmsg = ''
    # 每日先知文章群推送
    if(time.localtime().tm_hour == 8 and time.localtime().tm_min == 0):
        for group_n in group_list:
            group = await app.getGroup(group_n)
            rmsg = get_xz_article()
            await app.sendGroupMessage(group, MessageChain(__root__=[Plain( rmsg )]))

    # 每日看雪文二进制章群推送
    if(time.localtime().tm_hour == 9 and time.localtime().tm_min == 0):
        rmsg = get_kx_binary_article()
        for group_n in group_list:
            group = await app.getGroup(group_n)
            await app.sendGroupMessage(group, MessageChain(__root__=[Plain( rmsg )]))
            
    # 每日看雪密码学文章群推送
    if(time.localtime().tm_hour == 12 and time.localtime().tm_min == 0):
        rmsg = get_kx_crypto_article()
        for group_n in group_list:
            group = await app.getGroup(group_n)
            await app.sendGroupMessage(group, MessageChain(__root__=[Plain( rmsg )]))
            
    # 每日看雪逆向文章群推送
    if(time.localtime().tm_hour == 22 and time.localtime().tm_min == 0):
        rmsg = get_kx_reverse_article()
        for group_n in group_list:
            group = await app.getGroup(group_n)
            await app.sendGroupMessage(group, MessageChain(__root__=[Plain( rmsg )]))
    '''
    # 每日看雪区块链文章群推送
    if(time.localtime().tm_hour == 12 and time.localtime().tm_min == 0):
        rmsg = get_kx_blockchain_article()
        for group_n in group_list:
            group = await app.getGroup(group_n)
            await app.sendGroupMessage(group, MessageChain(__root__=[Plain( rmsg )]))
    '''
    # 每日看ctf赛事群推送
    if(time.localtime().tm_hour == 20 and time.localtime().tm_min == 0):
        rmsg = get_ctf_comming_match()
        for group_n in group_list:
            group = await app.getGroup(group_n)
            await app.sendGroupMessage(group, MessageChain(__root__=[Plain( rmsg )]))
    
    # 每日好友推送
    if(time.localtime().tm_hour == 7 and time.localtime().tm_min == 0):
        rmsg = '早安！ 宝贝 \n'
        rmsg += daily_words[random.randint(0, len(daily_words) - 1)]
        friend_list = await app.friendList()
        for friend in friend_list:
            
            await app.sendFriendMessage(friend, MessageChain(__root__=[Plain( rmsg )]))

    # 每日好友推送
    if(time.localtime().tm_hour == 23 and time.localtime().tm_min == 30):
        rmsg = '晚安！宝贝 \n'
        rmsg += daily_words[random.randint(0, len(daily_words) - 1)]
        friend_list = await app.friendList()
        for friend in friend_list:
            await app.sendFriendMessage(friend, MessageChain(__root__=[Plain( rmsg )]))
    
class SendMsgEvent(BaseEvent):
    id = 0
    is_group = False
    msg = ''
    def __init__(self, id, msg, is_group = False):
        super().__init__(id = id, msg = msg, is_group = is_group)
    class Dispatcher(BaseDispatcher):        
        async def catch(self, interface: DispatcherInterface):
            return 'ok'

@bcc.receiver("SendMsgEvent")
async def send_msg_listener(event: SendMsgEvent):
    print("send: id " + str(event.id) + ' ' +  event.msg)
    if(event.is_group == True):
        group = await app.getGroup(event.id)
        await app.sendGroupMessage(group, MessageChain(__root__=[Plain( event.msg )]))
    else:
        friend = await app.getFriend(event.id)
        await app.sendFriendMessage(friend, MessageChain(__root__=[Plain( event.msg )]))


@route('/sendmsg', method = 'POST')
def hello_world():
    t_id = request.params.get('id')
    t_type = request.params.get('type')
    t_token = request.params.get('token')
    
    if(t_token != 'r0se_token' or t_id == None or t_type == None):
        return 'error'
    msg = request._get_body_string().decode()
    print('id ' + str(t_id) + '  type: ' + str(t_type) + ' token ' + str(t_token))
    print('msg: ' + str(msg))

    if(t_type == 'group'):
        event = SendMsgEvent(int(t_id), msg, is_group=True)
        bcc.postEvent(event)
    elif(t_type == 'friend'):
        event = SendMsgEvent(int(t_id), msg, is_group=False)
        bcc.postEvent(event)
    return 'ok'

def run_r0se_api():
    run(host='0.0.0.0', port=9999)
def show_logo():
    s = '''\n
____   ___           \n
|  _ \ / _ \ ___  ___ \n
| |_) | | | / __|/ _ \\ \n
|  _ <| |_| \__ \  __/ \n
|_| \_\\___/|___/\___|\n'''
    print(s)
if __name__ =="__main__":
    show_logo();
    print('encoding: ' + sys.stdout.encoding)
    ft = threading.Thread(target=run_r0se_api)
    ft.start()
    app.launch_blocking()
