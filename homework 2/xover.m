 function [newpop] = xover(pop,xpro)
[x,y]=size(pop);
newpop=zeros(x,y);
for i=1:2:x-1
    if(rand<xpro)   %ִ�н���
        xpoint=sort(randperm(y,2)); 
        s=xpoint(1);t=xpoint(2);    %order 1 ����λ��
        xsize=t-s+1;
        index=zeros(2,y);
        newpop(i,1:xsize)=pop(i,s:t);       %���ƶ�Ӧλ��
        newpop(i+1,1:xsize)=pop(i+1,s:t);
        for j=1:y
            if ismember(pop(i+1,j), newpop(i,1:xsize))  %index1�Ƕ���pop_(i+1)��˵��
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
        addpop1(find(addpop1==0))=[];       %ȥ��0Ԫ��
        addpop2(find(addpop2==0))=[];
        newpop(i,xsize+1:y)=addpop1;        %��ӵ�newpop��
        newpop(i+1,xsize+1:y)=addpop2;
    else    %��ִ�н���
        newpop(i,:)=pop(i,:);
        newpop(i+1,:)=pop(i+1,:);
    end
end
end