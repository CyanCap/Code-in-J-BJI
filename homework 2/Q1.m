clc;clear;
global dis
xpro=0.9;   %交叉概率
insertpro=0.2; %插入突变概率
swappro=0.3;   %交换突变概率
its=50;       %迭代次数
num=20;         %种群大小

dis=[0,8,3,1,4,9,3,6;8,0,5,10,11,4,3,6;3,5,0,8,7,1,5,12;1,10,8,0,9,11,6,4;...
    4,11,7,9,0,5,17,3;9,4,1,11,5,0,4,1;3,3,5,6,17,4,0,7;6,6,12,4,3,1,7,0];

pop=initpop(dis,num);

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
    
    if i<=1                     %记录最优路线
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

    drawnow;
    hold off
    plot(x,yopt,'b');
    title(['its=',num2str(i),'  distance=',num2str(yopt(i))]);
    legend('最短路径');
    pop=pop_4;
    pop(end,:)=path;
end
path
yopt(its)
