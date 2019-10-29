<?php   
// Fibonacci series 

function fibonacci(int $number): int
{
  if ($number == 0 || $number == 1) {
    return $number;
  }

 return fibonacci($number - 1) + fibonacci($number - 2);
}

echo fibonacci(10);
