clc;clear;
format long g
global dis
xpro=0.9;   %�������
insertpro=0.2; %����ͻ�����
swappro=0.3;   %����ͻ�����
its=100000;       %��������
num=100;
location=csvread("st70.csv");
dis=discal(location);           %����������
pop=initpop(dis,num);               %��ʼѡ�������Ⱥ
yopt=zeros(1,its);
x=1:its;
for i=1:its
    v1=totaldis(pop);
    
    pop_1=selection(pop,v1);
    pop_2=xover(pop_1,xpro);
    pop_3=mutation_insert(pop_2,insertpro);
    pop_4=mutation_swap(pop_3,swappro);
    
    v2=totaldis(pop_4);
    [indopt,disopt]=findopt(pop_4,v2);
        
    if i<=1                     %��¼����·��
        yopt(i)=disopt;
        path=indopt;
    else
        if yopt(i-1)>=disopt
            yopt(i)=disopt;
            path=indopt;
        else
            yopt(i)=yopt(i-1);
        end
    end
    yavg(i)=mean(v2);
    ymax(i)=max(v2);
    drawnow;
    hold off
    plot(x,yopt,'b');
    title(['its=',num2str(i),'  distance=',num2str(yopt(i))]);
    legend('���·��')
    pop=pop_4;
    pop(end,:)=path;
end
path
yopt(its)