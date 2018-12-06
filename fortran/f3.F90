program f3

implicit none
integer :: a

print *, "Input the integer: "
read *, a

if (a == (a/3) * 3 .and. a == (a/5) * 5) then
        print *, "FizzBuzz"
else if (a == (a/3) * 3) then
        print *, "Fizz"
else if (a == (a/5) * 5) then
        print *, "Buzz"
end if

end program
