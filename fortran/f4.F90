program f4

implicit none

integer :: a, b

print *, "Enter the values of a and b: "
read *, a, b

if(b == (b/a) * a) then
        print *, a, " is a divisor of ", b
else
        print *, a, " is not a divisor of ", b
end if

end program
