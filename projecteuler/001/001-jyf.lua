#!/usr/bin/lua

sum = 0
i = 1

bingo = {0,3,5,6,9,10,12}


while i<1000000 do
    if (i%3 == 0) or (i%5 == 0) then
        sum = sum + i
    end
    i = i + 1
end

print(sum)
