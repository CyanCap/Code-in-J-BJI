function [newpop] = mutation_insert(pop,mpro)
[x,y]=size(pop);
newpop=zeros(x,y);
for i=1:1:x
    if(rand<mpro)                       %执行插入变异
        newpop(i,:)=pop(i,:);
        xpoint=sort(randperm(y,2));
        s=xpoint(1);t=xpoint(2);        %突变位置
        for j=s:t-1
            temp1=newpop(i,j+1);
            if j==s
                newpop(i,j+1)=newpop(i,t);
            else
                newpop(i,j+1)=temp2;
            end
            temp2=temp1;
        end
    else            %不执行变异
        newpop(i,:)=pop(i,:);
    end
end