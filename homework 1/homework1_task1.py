import numpy as np
from sklearn.preprocessing import StandardScaler
import math

X=np.asarray([[24,56,78],[5,66,52],[92,42,82],[31,63,67],[15,70,44],[12,45,35]])
Y=np.asarray([1,0,1,1,0,0])
ip=np.zeros((6,1))
err=np.zeros((6,1))

sc = StandardScaler()
X = sc.fit_transform(X)

w0=0.5
w1=w2=w3=0
epo=1
lr=0.1
m=0
g=0

for epo in range(1,4):
    for m in range(0,6):
        ip[m,0]=w0+w1*X[m,0]+w2*X[m,1]+w3*X[m,2]
        g=1/(1+(math.exp(-ip[m,0])))
        g_d=g*(1-g)
        err[m,0]=Y[m]-g
        w0=w0+lr*err[m,0]*g_d
        w1=w1+lr*err[m,0]*g_d*X[m,0]
        w2=w2+lr*err[m,0]*g_d*X[m,1]
        w3=w3+lr*err[m,0]*g_d*X[m,2]
        m=m+1
    # print("Output for epoch%d is %.4f, %.4f, %.4f, %.4f" %(epo, w0, w1, w2, w3))
    epo=epo+1

W=np.array([[w1,w2,w3],
            [w1,w2,w3],
            [w1,w2,w3],
            [w1,w2,w3],
            [w1,w2,w3],
            [w1,w2,w3]])
y_test=np.sum(X*W,axis=1)+w0
print(y_test)
MSE=np.sum((Y-y_test)**2)/6
print(MSE)


