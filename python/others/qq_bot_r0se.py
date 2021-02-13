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
import asyncio
import random
#import threading
import requests
import hashlib
import os
import time

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

def get_info_df_stock():
    rmsg = "东方财富\n"
    rmsg += "1 -> 五梁液: http://quote.eastmoney.com/sz000858.html"
    rmsg += "2 -> 比亚迪: http://quote.eastmoney.com/sz002594.html"
    rmsg += "3 -> 平安银行: http://quote.eastmoney.com/sz000001.html"
    rmsg += "4 -> "

# 基础信息
loop = asyncio.get_event_loop()
bcc = Broadcast(loop=loop)
app = GraiaMiraiApplication(
    broadcast=bcc,
    connect_info=Session(
        host="http://localhost:8080", # httpapi 服务运行的地址
        authKey="ILOVEI0GAN",         # 在setting.yml中设置的authKey
        account=1557203539,           # 机器人的 qq 号
        websocket=True                # Graia 已经可以根据所配置的消息接收的方式来保证消息接收部分的正常运作.
    )
)

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
    rmsg += "进程信息:\n"
    rmsg += os.popen("top -n 1").read() + "\n"
    rmsg += "\n"
    return rmsg

def personal(msg, friend = None, isgroup = False):
    rmsg = "" # 回复的消息
    r2msg = ""
    reply = []
    if msg.startswith("你好") or msg.startswith("hello") or msg.startswith("hi") or msg.startswith("哈喽"):
        reply = ["嗯嗯！你好呀！", "你好呀！", "hello!", "哈哈，你好呀!", "有啥事?"]
        if(isgroup != False):
            if(friend.remark != ''):
                rmsg = friend.remark + ", "
            else:
                rmsg = friend.nickname + ", "
    elif msg.startswith("来首诗"):
        reply = ["凡事都有定期，天下万务都有定时。……哭有时，笑有时；哀恸有时，跳舞有时；抛掷石头有时，堆聚石头有时；怀抱有时，不怀抱有时……",
           "不能朽、不能见，独一的真神。", "赐生命与气息予大小生灵，\n活在万有中，惟你是真生命\n；我们有如花草，今朝虽茂盛，\n明朝即枯残，惟你永不变更。\n"
           ]
    elif "是不是" in msg:
        reply = ["是的", "不是", "干嘛告诉你呀"]
    elif msg.startswith("叫") and ( "哥" in msg or "爸" in msg or "妈" in msg or "爷" in msg):
        reply = ["叫你妹呀！", "你觉得我是你妈吗?", "搞笑，你觉得我会叫你吗?"]
    elif ("知道" in msg or "晓得" in msg) and ("吗" in msg or "?" in msg):
        reply = ["不要问我，我咋个晓得！", "你有病吧！", "我不晓得", "问我干嘛，去百度啊！", "你怎么啥都不知道？", "就这！还要我回答？"]
    elif "龟孙" in msg or "操" in msg or "你妈" in msg or "你妹" in msg or "fuck" in msg or "tmd" in msg or "sb" in msg or "TMD" in msg or "死了" in msg or "滚" in msg or "撒比" in msg or "憨逼" in msg or "智障" in msg or "狗日的" in msg:
        reply = ["滚!", "你是不是想死?", "你是不是欠奏?", "操你妹!", "真的有病!", "给我滚！", "不理你了", "你是皮子痒了？"]
    elif "在干嘛" in msg or "在忙啥" in msg or "忙什么" in msg or "干什么" in msg:
        reply = ["没干嘛", "在做饭", "在聊天呀", "关你屁事!", "有事找我呀", "在外面玩", "在逛街", "在吃烧烤", "在吃火锅", "在做作业", "在上课", "在化妆"]
    elif "在吗" in msg or "在不" in msg or "在?" in msg:
        reply = ["在", "在的", "嗯嗯", "有啥事?", "干嘛?", "你想我了？"]
    elif "吃饭" in msg and ("没" in msg or "吗" in msg or "?" in msg):
        reply = ["正在吃唉", "快了,你呢?", "没有，刚刚吃过"]
    elif "好" in msg and "吗" in msg:
        reply = ["你觉得呢?", "肯定的啦", "没感觉!"]
    elif "翻译" in msg or "trans" in msg:
        rmsg = "翻译如下:\n"
        if(msg.startswith("trans")):
            text = translate(msg[5:])
        else:
            text = translate(msg[2:])
        reply = [text]
    elif "找你聊聊" in msg or "随便聊" in msg:
        reply = ["我有啥好聊的", "聊什么", "你先说吧", "emem， 聊啥?", "你说吧！", "直接说事"]
    elif "嗯" in msg or "哦" in msg:
        reply = ["哦?", "?", "嗯?", "???", "...", "。。。", ":)"]
    elif "有事没" in msg:
        reply = ["当然有事", "没事", "关你啥事?"]
    elif "有事" in msg or ("说" in msg and "事" in msg):
        reply = ["不要找我，听到没", "快滚快滚", "有啥事?", "不要来烦我！", "别来找我", "滚", "好吧，你说", "嗯嗯，说吧"]
    elif "也是" in msg or "是的" in msg:
        reply = ["嗯嗯?", "哦哦", "好吧"]
    elif msg.startswith("和谁聊"):
        reply = ["关你屁事!", "你是其中一个", "和你呀!", "你管我和谁聊"]
    elif "你是" in msg or "你叫" in msg:
        reply = ["我是你的妈妈!", "我是谁并不重要，重要的是你是谁你都不知道", "我是你的人", "哈哈哈，你既然不知道我是谁?", "连我都不知道，切!", "人家叫小玫瑰嘛，既然连我都不知道。。。"]
    elif "赶快说" in msg or "别废话" in msg:
        reply = ["说你妹的说！", "不说!", "坚决不说", "我干嘛要说？", "你算老几?"]
    elif ("帮我" in msg or "给我" in msg) and ("?" in msg or "吗"):
        reply = ["去找别人吧", "不帮", "不想帮你"]
    elif ("你在" in msg) and ("哪" in msg):
        reply = ["在厨房做菜", "在公园玩!", "在家里打游戏", "在广场玩"]
    elif "想你" in msg:
        reply = ["想我我?", "你这个小屁孩，快点去好好读书吧", "想我干嘛?", "我也想你了"]
    elif msg.startswith("好"):
        reply = ["晓得就好", "嗯嗯"]
    elif "拜" in msg or "bye" in msg or "再见" in msg:
        reply = ["好的，拜拜", "快滚,快滚", "嗯嗯，再见", "嗯嗯，好的", "拜拜", "bye bye"]
    elif "不知道" in msg:
        reply = ["不知道，去百度呀", "不知道?，你这都不知道?", "自己去google", "要我告诉你呀！"]
    elif "天气" in msg:
        reply = ["天气很好呀", "你不会看自己在手机上看吗", "不行，我这下雨了", "打雷了，好害怕！"]
    elif "汽车" in msg or "小车" in msg:
        reply = ["你打算买啥车呀?", "车，我觉得买两个，一个自己的爱车，另一个就是家用车啦", "你有钱买车吗？", "你存款够吗？", "你打算买车?", "你打算买啥车?", "价格多少？"]
    elif "车" in msg and "有" in msg and "吗" in msg:
        reply = ["我有没有，关你啥事?", "有的，我有一辆法拉！", "只要你是我的爱人，我送给你", "没有唉，赶快送我一辆Musting"]
    elif "打算" in msg and "过" in msg:
        reply = ["不想过了", "开开心心的过就好啦！", "我们两一起过吧！"]
    elif "i0gan" in msg or "I0gan" in msg or "徐绿国" in msg or "xlg" in msg or "XLG" in msg:
        reply = ["i0gan是你们的老大哥，你们必须要听他的", "i0gan是我的Hero啦", "是你爹!", "他说话有好听，人又长得帅，谁不喜欢呀"]
    elif "hppi0" in msg or "李恒飞" in msg or "lhf" in msg or "LHF" in msg:
        reply = ["江湖老渣男啦", "人长得帅，嘴很甜，爱好: 撩妹子", "口算md5解密。手机，电脑，保险箱，还有女人密码，用脚都能帮你破解出来"]
    elif "cjr" in msg:
        reply = ["暖男啦，超喜欢啦", "长的超级帅，高高的，他也许看不到我吧!", "WEB都能给你日穿"]
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
    elif "是什么" in msg:
        reply = ["你问我，我问谁呀", "你不会google吗", "你不会百度吗?", "问别人去"]
    elif "不" in msg and ("问" in msg or "做" in msg) and "了" in msg:
        reply = ["就这?", "就这么妥协了?", "这么就放弃了?", "没出席！"]
    elif msg == "早" or msg == "早!" or "早安" in msg or "早上好" in msg or "早啊" in msg or "good morning" in msg:
        reply = ["早呀", "起这么早，我还以为你能睡呢", "怎么现在才起?", "早上好呀", "早!"]
    elif "晚安" in msg or "good night" in msg or "该睡了" in msg or "该睡觉了" in msg or "睡了吧" in msg or "睡觉" in msg or "睡了" in msg:
        reply = ["嗯嗯，好的，早睡早起", "现在不是还早吗?", "太早了，等一会儿就睡", "好的，我马上就睡了，晚安", "好, 晚安", "晚安！", "嗯嗯，晚安", "好的，晚安"]
    elif "你" in msg and ("喜欢" in msg or "爱好" in msg) and ("什么" in msg or "啥" or "是"):
        reply = ["我喜欢唱跳rap还有篮球，你呢?", "年轻人劝你耗子尾汁，以后不要再耍这样的小聪明！", "你猜猜", "不告诉你，死渣男!", "你想知道吗?", "我喜欢与你聊天"]
    elif ("快" in msg and ("告诉" in msg or "说" in msg or "讲" in msg)) or msg.startswith("说呀"):
        reply = ["我干嘛要告诉你", "我干嘛要说", "你是谁呀，我跟你说有必要吗?", "我告诉你，你就是个白痴！", "不告诉你", "就不说"]
    elif "关心我" in msg:
        reply = ["我干嘛要关心你?", "你是谁呀!", "切！哪来的狗"]
    elif "获取文章" in msg or "最新文章" in msg:
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
    elif "过年" in msg or "新年" in msg:
        reply = ["新年快乐哦!", "哈哈！新年快乐！"]
    elif "什么?" in msg:
        reply = ["自己不会百度吗?", "什么呀?", "不明白?", "自己去google", "什么鬼，不明白?"]
    elif "美女" in msg:
        reply = ["你这是在贬低我，人家是仙女嘛!", "你咋个知道我是美女?", "你是不是喜欢我?"]
    elif "几点" in msg or "时间" in msg:
        reply = ["不告诉你", "现在时间是: " + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) ]
    elif "博客" in msg and "我" in msg:
        reply = ["亲！, i0gan的博客链接: http://i0gan.cn"]
    elif "新闻" in msg:
        reply = ["在测试中，后面发给你!"]
    elif "获取系统" in msg:
        reply = [get_system_info()]
    elif "歌" in msg or "音乐" in msg or "再来一首" in msg:
        global songs
        songs_list = list(songs.keys())
        song_name = songs_list[random.randint(0, len(songs_list) - 1)]
        link = find_song(song_name)
        reply = ['好的，随机播放: \n' + song_name + '  播放: ' + link]
    elif msg.startswith("播放") or msg.startswith("来首"): #点歌
        song_name = msg[2:]
        link = find_song(song_name)
        if(link == ''):
            reply = [song_name + ' 没有找到相关歌曲唉']
        else:
            reply = [song_name + '  播放: ' + link]
    elif msg.startswith("我要听"):
        song_name = msg[3:]
        link = find_song(song_name)
        if(link == ''):
            reply = [song_name + ' 没有找到相关歌曲唉']
        else:
            reply = [song_name + '  播放: ' + link]
    elif "烟花" in msg:
        reply = ["我喜欢看烟花", "烟花真好看", "哈哈，能一起去看烟花吗?"]
    elif "机器人" in msg or "bot" in msg:
        reply = ["你才是机器人呢！", "我不是机器人，我是r0se，某公司的CEO！", "你在说我?", "在想啥呢？谁是机器人呀！"]
    elif "你" in msg and "是" in msg and "?" in msg:
        reply = ["我肯定不是啊", "你是", "不是", "肯定不是呀"]
    elif "你" in msg and ("为啥" in msg or "怎么" in msg):
        reply = ["没为啥", "怎么了?", "管你啥事？"]
    elif "没怎么" in msg:
        reply = ["哦哦", "嗯嗯", "你是不是有事?", "那就好"]
    elif msg.startswith("没事"):
        reply = ["哦哦", "嗯嗯", "那就好", "说嘛！", "到底有没有事？"]
    elif "男朋友" in msg:
        reply = ["谁敢要那些臭男人", "我的男朋友是lhf，但是他有juo臭", "到处都是渣男呀，不玩"]
    elif msg.startswith("谁") and len(msg) <= 2:
        reply = ["要我告诉你?", "干嘛告诉你", "不想告诉你！", "你个死渣男，想撩我呀！", "不告诉你！"]
    elif "真的" in msg and "?" in msg:
        reply = ["你说呢?", "真的啦", "肯定是真的啦", "假的"]
    elif "喜欢你" in msg:
        reply = ["我也喜欢你", "真的假的？", "你怎么现在才说，等到话都谢了！"]
    elif "干嘛？" in msg or "干嘛?" in msg:
        reply = ["没干嘛", "没什么", "没事啦！"]
    elif "pwn" in msg or "PWN" in msg:
        reply = ["啊，遇到了大佬！", "PWN大佬来了，群地位-1", "听说你能pwn天pwn地pwn卫星？"]
    elif "爱情" in msg or "恋爱" in msg:
        reply = ["爱情就是shit!", "爱情是TMD什么狗屁！", "女人只会阻止你前进的脚步！", "爱情只会让你失去理智", "你陪拥有爱情吗？", "你是什么狗屁，你陪吗？", "滚你妈蛋的爱情！"]
    else:
        reply = ["啥子意思?", "哦哦，明白!", "不晓得唉！", "你在说啥子哦！", "嗯嗯！", "你说这干啥？", "干嘛说这些？", "你是故意的吗？", "不想跟你说话！", "别问我，我不晓得！", "我不太懂！", "不要烦我！听到没。"]
    rmsg += reply[random.randint(0, len(reply) - 1)]
    return rmsg

# 接收群消息
@bcc.receiver("GroupMessage")
async def group_message_handler(app: GraiaMiraiApplication, message: MessageChain, group: Group,member: Member):
    if(group.id == 729054809 or group.id == 791894520 or group.id == 702968511):
        msg = message.asDisplay()
        rmsg = personal(msg)
        await app.sendGroupMessage(group, MessageChain(__root__ = [Plain( rmsg )]))

# 回复好友事件.
@bcc.receiver("FriendMessage")
async def friend_message_listener(message: MessageChain, friend: Friend, app: GraiaMiraiApplication):
    print(str(friend.id) + " " + friend.nickname + " " + friend.remark)
    msg = message.asDisplay()
    rmsg = personal(msg, friend=friend)  
    await app.sendFriendMessage(friend, MessageChain(__root__=[Plain( rmsg )]))

app.launch_blocking()