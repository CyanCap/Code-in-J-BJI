import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from tensorflow import keras
from tensorflow.keras import layers
from sklearn.preprocessing import MinMaxScaler
from keras import regularizers

#### 数据处理部分 ####

# 读入数据
for m in range(15,1821):
    google_stock = pd.read_excel('gold.xlsx')
    google_stock.tail()  # 查看部分数据
    google_stock.head()

    # 时间戳长度
    time_stamp = 1  # 输入序列长度

    # 划分训练集与验证集
    date = google_stock['Date']
    google_stock = google_stock[['USD (PM)']]
    train = google_stock[0:m] #训练集
    valid = google_stock[m-5:int(1.3*m)+20]  #验证集
    test = google_stock[1:]  #测试集

    # 归一化
    scaler = MinMaxScaler(feature_range=(0, 1))
    scaled_data = scaler.fit_transform(train)
    x_train, y_train = [], []

    # 训练集切片
    for i in range(time_stamp, len(train) - 5):
        x_train.append(scaled_data[i - time_stamp:i])
        y_train.append(scaled_data[i: i + 5])

    x_train, y_train = np.array(x_train), np.array(y_train).reshape(-1, 5)

    # 验证集切片
    scaled_data = scaler.fit_transform(valid)
    x_valid, y_valid = [], []
    for i in range(time_stamp, len(valid) - 5):
        x_valid.append(scaled_data[i - time_stamp:i])
        y_valid.append(scaled_data[i: i + 5])

    x_valid, y_valid = np.array(x_valid), np.array(y_valid).reshape(-1, 5)

    # 测试集切片
    scaled_data = scaler.fit_transform(test)
    x_test, y_test = [], []
    for i in range(time_stamp, len(test) - 5):
        x_test.append(scaled_data[i - time_stamp:i])
        y_test.append(scaled_data[i: i + 5])

    x_test, y_test = np.array(x_test), np.array(y_test).reshape(-1, 5)
    #### 建模部分 ####
    model = keras.Sequential()
    model.add(layers.LSTM(64, return_sequences=True, input_shape=(x_train.shape[1:])))
    model.add(layers.LSTM(64, return_sequences=True))
    model.add(layers.LSTM(32))
    model.add(layers.Dropout(0.1))
    model.add(layers.Dense(5))

    model.compile(optimizer=keras.optimizers.Adam(), loss='mae', metrics=['accuracy'])
    learning_rate_reduction = keras.callbacks.ReduceLROnPlateau(monitor='val_loss', patience=3, factor=0.7,
                                                                min_lr=0.000000005)

    history = model.fit(x_train, y_train,
                        batch_size=128,
                        epochs=100,
                        validation_data=(x_valid, y_valid),
                        callbacks=[learning_rate_reduction])

    # loss变化趋势可视化
    # plt.plot(history.history['loss'],label='training loss')
    # plt.plot(history.history['val_loss'], label='val loss')
    # plt.show()
    closing_price = model.predict(x_test)
    model.evaluate(x_test)
    scaler.fit_transform(pd.DataFrame(valid['USD (PM)'].values))

    # 反归一化
    closing_price = scaler.inverse_transform(closing_price.reshape(-1, 5)[:, 0].reshape(1, -1))  # 只取第一列
    y_test = scaler.inverse_transform(y_test.reshape(-1, 5)[:, 0].reshape(1, -1))

    # 计算预测结果
    rms = np.sqrt(np.mean(np.power((y_test[0:1, 5:] - closing_price[0:1, 5:]), 2)))
    print(rms)
    print(closing_price.shape)
    print(y_test.shape)

    # 预测效果可视化
    dict_data = {
        'Predictions': closing_price.reshape(1, -1)[0],
        # 'Value': y_test[0]

    }
    data_pd = pd.DataFrame(dict_data)
    plt.clf()
    plt.plot(data_pd[['Predictions']][0:], linewidth=1, alpha=0.8)
    # plt.plot(data_pd[['Value']][0:],linewidth=1,alpha=1.0)
    plt.xlabel('time')
    plt.ylabel('USD (PM)')
    # plt.title('prices in future 30 ticks')
    # plt.plot(data_pd[['Predictions']],linewidth=1.2)
    # figure = plt.figure(figsize=(10,10))
    # axes = figure.add_subplot(111) #插入面板2
    # axes.plot(data_pd[0:30])
    # axes.set_xlabel('tick')
    # axes.set_ylabel('price')
    # axes.set_title('30tick')
    # plt.show()
    # plt.plot(data_pd[0:30])
    dataframe = pd.DataFrame(data_pd[0:])

    xname = '.\datagna\pre' + str(m) + '.xlsx'
    pname = 'D:\huidu\picgna\pic' + str(m)
    dataframe.to_excel(xname)
    plt.savefig(pname, dpi=500)



