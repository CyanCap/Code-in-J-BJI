function [newpop] = selection(pop,disvalue)
ndisvalue=1./disvalue;
sfitness=sum(ndisvalue);
ndisvalue=ndisvalue./sfitness;
ndisvalue=cumsum(ndisvalue);
[x,y]=size(pop);
spro=sort(rand(x,1));   %—°∂®∏≈¬ ≈≈–Ú
newpop=zeros(x,y);
i=1;j=1;
while i<=x
    if spro(i)<ndisvalue(j)
        newpop(i,:)=pop(j,:);
        i=i+1;
    else
        j=j+1;
    end
end

