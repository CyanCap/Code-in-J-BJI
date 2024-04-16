clear;clc

c=1;
c_max=50;
a=0;
posmin=zeros(c_max,1);
best=-ones(c_max,1);
while c<=c_max
    ACO_TSP;
    posmin(c) = find(l_best==min(l_best),1);
    best(c) = min(l_best);
    
    c=c+1;
    a=a+0.2;
end
subplot(1,2,1);
plot(0:0.2:(a-0.2),posmin,'b');
ylim([0 20]);
xlabel('values of ¦Á');ylabel('iteration');
title('iteration to reach the optimal result for different ¦Á');
subplot(1,2,2);
plot(0:0.2:(a-0.2),best,'r');
xlabel('values of ¦Á');ylabel('best distance');
title('best value for different ¦Á');

