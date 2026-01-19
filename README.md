# Numerical Solution of First-Order Differential Equations in C++

This project presents a C++ implementation of standard numerical methods for solving first-order ordinary differential equations (ODEs) of the form

\[
\frac{dy}{dx} = f(x, y)
\]

The program is designed for educational and computational purposes, allowing users to compare the accuracy of different numerical techniques.

---

## Overview

The code numerically approximates solutions of first-order ODEs using the following methods:

1. Euler Method  
2. Modified Euler Method (Heun’s Method)  
3. Fourth-Order Runge–Kutta Method (RK4)

A single interface function allows selection of the desired method and computation of the approximate solution at a specified point.

---

## Differential Equation (Example)

The differential equation currently implemented in the program is:

\[
\frac{dy}{dx} = 2xy
\]

The analytical solution of this equation is:

\[
y = e^{x^2} + C
\]

The differential equation can be easily modified to solve other first-order ODEs.
