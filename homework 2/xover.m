 function [newpop] = xover(pop,xpro)
[x,y]=size(pop);
newpop=zeros(x,y);
for i=1:2:x-1
    if(rand<xpro)   %执行交叉
        xpoint=sort(randperm(y,2)); 
        s=xpoint(1);t=xpoint(2);    %order 1 交叉位置
        xsize=t-s+1;
        index=zeros(2,y);
        newpop(i,1:xsize)=pop(i,s:t);       %复制对应位置
        newpop(i+1,1:xsize)=pop(i+1,s:t);
        for j=1:y
            if ismember(pop(i+1,j), newpop(i,1:xsize))  %index1是对于pop_(i+1)来说的
                index(1,j)=0;
            else
                index(1,j)=1;
            end
            if ismember(pop(i,j), newpop(i+1,1:xsize))
                index(2,j)=0;
            else
                index(2,j)=1;
            end
        end
        addpop1=pop(i+1,:).*index(1,:);
        addpop2=pop(i,:).*index(2,:);
        addpop1(find(addpop1==0))=[];       %去除0元素
        addpop2(find(addpop2==0))=[];
        newpop(i,xsize+1:y)=addpop1;        %添加到newpop里
        newpop(i+1,xsize+1:y)=addpop2;
    else    %不执行交叉
        newpop(i,:)=pop(i,:);
        newpop(i+1,:)=pop(i+1,:);
    end
end
end