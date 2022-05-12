# coding=utf-8
import math
import tushare as ts
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import talib
matplotlib.rcParams['axes.unicode_minus']=False
plt.rcParams['font.sans-serif']=['SimHei']
ts.set_token('32ef323a20cd242be555b89f758762482afa9064796f1a34fcdd633c')#这里是token码 获取地址  https://tushare.pro/register?reg=385920（需注册）
pro = ts.pro_api()
df1= pro.query('daily_basic', ts_code='', trade_date='20181101',fields='ts_code,trade_date,total_mv,ps,pe,pb')#获取数据
#条件
df1=df1[   df1['pe']<20    ] 
df1=df1[   df1['pb']<2     ] 
df1=df1[   df1['ps']<5     ] 
df1=df1[   df1['total_mv']<1000000   ]
#排序选股
df1=df1.sort_values(by="pe" , ascending=True)
df1=df1.head(50)#按由低到高排，选前100名
df1=df1.sort_values(by="ps" , ascending=True)
df1=df1.head(30)
df1=df1.sort_values(by="pb" , ascending=True)
df1=df1.head(10)
df1=df1['ts_code']#获得一篮子股票
df1.values.tolist()#转换成列表
stock=','.join(df1) #转换成浮点，用逗号隔开
cum=0
for i in df1:
    df=pro.query('daily', ts_code=i, start_date='20181101', end_date='20190410',fields='')   
    df=df.sort_index()
    df.index=pd.to_datetime(df.trade_date,format='%Y-%m-%d')#设置日期索引
    ret=df.change/df.close
    dd=pd.Series(1,index=df.close.index)
    cumqq=ret*dd.shift(1).dropna()
    cum=(np.cumprod(1+ret[cumqq.index[0:]])-1)/len(df1)+cum#等权重配置一篮子股票
df12 = pro.index_daily( ts_code='000300.SH', start_date='20181101', end_date='20190410')
df12=df12.sort_index()
df12.index=pd.to_datetime(df12.trade_date,format='%Y-%m-%d')#设置日期索引
ret12=df12.change/df12.close
#将顺序颠倒
aq=pd.Series(1,index=df12.close.index) 
SmaRet=ret12*aq.shift(1).dropna()
cum12=np.cumprod(1+ret12[SmaRet.index[0:]])-1
plt.plot(cum,label="组合",color='r')
plt.plot(cum12,label="沪深300",color='b')
plt.title("小市值三因子选股策略收益率")
plt.legend()
f=cum[-2]*250/len(close)
f1=100*f#换成百分制
print("年化收益率：{:.2f}%,总收益{:.2f}%".format(f1,f1*len(close)/250))

