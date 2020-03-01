# Euler’s Totient Function

Euler’s Totient function (n) for an input n
is count of numbers in {1, 2, 3, …, n} that are relatively prime
to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.

+ φ(1) = 1
+ φ(2) = 1
+ φ(3) = 2
+ φ(4) = 2
+ φ(5) = 4
+ φ(6) = 2
+ φ(7) = 6
+ φ(8) = 4 
+ φ(9) = 6
+ φ(10) = 4

---

### Some Interesting Properties of Euler’s Totient Function:

1. For a prime number p, φ(p) is p-1. 
For example φ(5) is 4, pgi(7) is 6 and φ(13) is 12.
2. **For two numbers a and b,
if gcd(a, b) is 1, then φ(ab) = φ(a) * φ(b).**
3. **For any two prime numbers p and q, φ(pq) = (p-1)/*(q-1).**
4. If p is a prime number, then φ(p`) = pk – pk-1. 
5. **Sum of values of totient functions of all divisors of n is equal to n.**  
For example, n = 6, the divisors of n are 1, 2, 3 and 6.
According to Gauss, sum of φ(1) + φ(2) + φ(3) + φ(6) should be 6. 
We can verify the same by putting values, we get (1 + 1 + 2 + 2) = 6.
6. **a^φ(n) ≡ 1 (_mod_ n)**


### Solution
The idea is based on Euler’s product formula which states
that value of totient functions is below product over all prime factors p of n.  
![](https://wikimedia.org/api/rest_v1/media/math/render/svg/bb6b6388ded7d1e160a3bd82b60c5b593947088a)   
The formula basically says that the value of φ(n) is equal
to **n** multiplied by product of **(1 – 1/p)** for all prime factors
p of n. For example value of φ(6) = 6 * (1-1/2) * (1 – 1/3) = 2.