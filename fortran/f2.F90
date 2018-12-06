program f2

implicit none

real :: a, b, c, d
character(len = 20) :: name

print *, "Enter your name"
read *, name
print *, "Enter the values of a, b, and c"
read *, a, b, c

print *, "Hello ", name
print *, "The volume of the cube is: ", a*b*c

d = (a*b*c) / 7
print *, "The value of d is: ", INT(d)

end program
