function [newpop] = mutation_insert(pop,mpro)
[x,y]=size(pop);
newpop=zeros(x,y);
for i=1:1:x
    if(rand<mpro)                       %ִ�в������
        newpop(i,:)=pop(i,:);
        xpoint=sort(randperm(y,2));
        s=xpoint(1);t=xpoint(2);        %ͻ��λ��
        for j=s:t-1
            temp1=newpop(i,j+1);
            if j==s
                newpop(i,j+1)=newpop(i,t);
            else
                newpop(i,j+1)=temp2;
            end
            temp2=temp1;
        end
    else            %��ִ�б���
        newpop(i,:)=pop(i,:);
    end
end