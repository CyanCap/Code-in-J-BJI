import numpy as np
import pandas as pd
import tensorflow as tf
from sklearn.preprocessing import LabelEncoder
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import confusion_matrix, accuracy_score

tf.__version__
dataset = pd.read_csv('codes\计算智能\homework 1\Churn_Modelling.csv')
X = dataset.iloc[:, 3:-1].values
y = dataset.iloc[:, -1].values
dataset = pd.read_csv('codes\计算智能\homework 1\Churn_Modelling.csv')
X = dataset.iloc[:, 3:-1].values
y = dataset.iloc[:, -1].values


le = LabelEncoder()
X[:, 2] = le.fit_transform(X[:, 2])

ct = ColumnTransformer(transformers=[('encoder', OneHotEncoder(), [1])], remainder='passthrough')
X = np.array(ct.fit_transform(X))

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

ann = tf.keras.models.Sequential()
ann.add(tf.keras.layers.Dense(units=6, activation='relu'))      #hidden layer 1
ann.add(tf.keras.layers.Dense(units=6, activation='relu'))      #hidden layer 2
ann.add(tf.keras.layers.Dense(units=1, activation='sigmoid'))   #output layer
ann.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])
ann.fit(X_train, y_train, batch_size = 32, epochs = 100)

#predict the customer
customer_infor=np.array([[600, "France", "Male",40, 3, 60000, 2, 1, 1, 50000]])
customer_infor[:,2]=le.transform(customer_infor[:,2])
customer_infor=ct.transform(customer_infor)
customer_infor=sc.transform(customer_infor)
customer_pred=ann.predict(customer_infor)

#Predicting the Test set results with threshold 0.5
y_pred_r=ann.predict(X_test)
y_pred=(y_pred_r>0.5)
cm=confusion_matrix(y_test,y_pred)
accuracy=accuracy_score(y_test,y_pred)
accuracy=accuracy*100

if customer_pred > 0.5:
    print("The customer will leave the bank. The probability of leave about the customer is %f." %customer_pred)
else:
    print("The customer will stay in the bank. The probability of leave about the customer is %f." %customer_pred)

print(cm)
print("Accuracy equals to %d%%" %accuracy)



