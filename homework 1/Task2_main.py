import numpy as np
import pandas as pd
import torch
import torch.nn as nn
import torch.optim as optim
from sklearn.compose import ColumnTransformer
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import StandardScaler

dataset = pd.read_csv('Churn_Modelling.csv')
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
class ANN(nn.Module):
    def __init__(self):
        super(ANN, self).__init__()
        self.fc1 = nn.Linear(X_train.shape[1], 6)
        self.fc2 = nn.Linear(6, 6)
        self.fc3 = nn.Linear(6, 1)
        self.sigmoid = nn.Sigmoid()

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        x = self.sigmoid(self.fc3(x))
        return x

ann = ANN()
optimizer = optim.Adam(ann.parameters())
criterion = nn.BCELoss()
X_train_tensor = torch.FloatTensor(X_train)
y_train_tensor = torch.FloatTensor(y_train).view(-1, 1)

for epoch in range(100):
    optimizer.zero_grad()
    outputs = ann(X_train_tensor)
    loss = criterion(outputs, y_train_tensor)
    loss.backward()
    optimizer.step()
    print(f"Epoch {epoch+1}/100, Loss: {loss.item()}")

# Customer's data
customer_data = np.array([[600, "France", "Male",40, 3, 60000, 2, 1, 1, 50000]])
customer_data[:, 2] = le.transform(customer_data[:, 2])
customer_data = ct.transform(customer_data)
customer_data = sc.transform(customer_data)
customer_data_tensor = torch.FloatTensor(customer_data)

with torch.no_grad():
    customer_pred = ann(customer_data_tensor)
    customer_pred_class = (customer_pred > 0.5).float()

print(f"Probability that the customer will leave the bank: {customer_pred.item():.4f}")

if customer_pred_class.item() == 1:
    print("The customer is likely to leave the bank.")
else:
    print("The customer is likely to stay with the bank.")

with torch.no_grad():
    customer_pred = ann(customer_data_tensor)
    customer_pred_class = (customer_pred > 0.5).float()



X_test_tensor = torch.FloatTensor(X_test)
y_pred = ann(X_test_tensor)
y_pred_class = (y_pred > 0.5).float()
cm = confusion_matrix(y_test, y_pred_class.detach().numpy())
accuracy = accuracy_score(y_test, y_pred_class.detach().numpy())
print(cm)
print(f"Accuracy: {accuracy*100:.2f}%")
