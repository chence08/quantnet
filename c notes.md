# A Tutorial Introduction

## Symbolic Constants

A `#define` line defines a symbolic name or symbolic constant to be a particular string of characters: `#define name replacement list`

The *name* has the same form as a variable name: a sequence of letters and digits that begins with a letter. The *replacement text* can be any sequence of characters; it is not limited to numbers.

```c
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table */
main() {
    int fahr;
    
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

## Character Input and Output

Text input or output, regardless of where it originates or where it goes to, is dealt with as streams of characters. A text stream is a sequence of characters divided into lines; each line consists of zero or more characters **followed by a newline character.**

> Computer only receives text stream after you press ENTER!

```c
c = getchar();
```

The variable `c` contains the next character of input. `putchar(c)` prints the content of the integer variable `c` as a character.

### File Copying

```c
#include <stdio.h>

/* copy input to output; 1st version */
main() {
    int c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

/* copy input to output; 2nd version */
main() {
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}
```

We must declare `c` to be a type big enough to hold any value that `getchar` returns. We can't use `char` since `c` must be big enough to hold `EOF` in addition to any possible char. Therefore we use `int`.

The parentheses around the assignment, within the condition are necessary. **The precedence of != is higher than that of =**, which means that in the absence of parentheses the relational test != would be done before the assignment =. So these statements are equivalent:

```c
c = getchar() != EOF
c = (getchar() != EOF)
```

This has the undesired effect of setting c to 0 or 1, depending on whether or not the call of getchar returned end of file.

### Character Counting

```c
#include <stdio.h>

/* count characters in input; 1st version */
main () {
    long nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}

/* count characters in input; 2nd version */
main () {
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
```

`printf` uses `%f` for both `float` and `double`; `%.0f` suppresses the printing of the decimal point and the fraction part, which is zero.

The body of the second for loop is empty, because all the work is done in the test and increment parts. But the grammatical rules of C require that a `for` statement to have a body. The isolated semicolon, called the null statement, is there to satisfy that requirement. We put it on a separate line to make it visible.

### Line Counting

Counting lines is just counting newlines.

```c
#include <stdio.h>

/* count lines in input */
main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```

### Word Counting

A word is any sequence of characters that does not contain a blank, tab or newline.

```c
#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
main() {
    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```

## Arrays

```c
#include <stdio.h>

/* count digits, white space, others */
main() {
    int c, i, nwhite, nother;
    int ndigit[10];
    
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0; // initialize array
    
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
    	else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
    	else
            ++nother;
    
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
```

> while loop works without braces

Array subscripts always start at zero in C, so the elements are `ndigit[0], ndigit[1], ..., ndigit[9]`. This is reflected in the `for` loops that initialize and print the array.

A subscript can be any integer expression, which includes integer variables like `i`, and integer constants.

## Functions

Function definitions can appear in any order, and in one source file or several, although no function can be split between files. If the source program appears in several files, you may have to say more to compile and load it than if it all appears in several files, but that is an operating system matter, not a language attribute.

## Arguments - Call by Value

In C, all function arguments are passed "by value". This means that the called function is given the values of its arguments in temporary variables rather than the originals. This usually leads to more compact programs with fewer extraneous variables, because parameters can be treated conveniently initialized local variables in the called routine.

```c
/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
    int p;
    for (p = 1; n > 0; --n)
        p *= base;
    return p;
}
```

Whatever is done to `n` inside `power` has no effect on the argument that `power` was originally called with.

When necessary, it is possible to arrange for a function to modify a variable in a calling routine. The caller must provide the *pointer* of the variable to be set, and the called function must declare the parameter to be a pointer and access the variable indirectly through it.

When the name of an array is used as an argument, the value passed to the function is the address of the beginning of the array - there is no copying of array elements.

## Character Arrays

## External Variables and Scope

Each local variable in a function comes into existence only when the function is called, and disappears when the function is exited. This is why such variables are usually known as **automatic** variables, following terminology in other languages.

Because automatic variables come and go with function invocation, they do not retain their values from one call to the next, and must be explicitly set upon each entry. **If they are not set, they will contain garbage.**

As an alternative to automatic variables, it is possible to define variables that are *external* to all functions, that is, variables that can be accessed by name by any function. **The variable must also be declared in each function that wants to access it;** this states the type of the variable. The declaration may be an explicit `extern` statement of may be implicit from context.

If the definition of the external variable occurs in the source file before its use in a particular function, then there is no need for an `extern` declaration in the function. In fact, common practice is to place definitions of all external variables at the beginning of the source file, and then omit all `extern` declarations.

**If the program is in several source files, and a variable in defined in *file1* and used in *file2* and *file3*, then `extern` declarations are needed in *file2* and *file3* to connect the occurrences of the variable. The usual practice is to collect `extern` declarations of variables and functions in a separate file, historically called a header, that is included by `#include` at the front of each source file. The suffix `.h` is conventional for header files.**

> **Definition** refers to the place where the variable is created or assigned storage; **Declaration** refers to places where the nature of the variable is stated but no storage is allocated.

# Types, Operators and Expressions

## Data Types and Sizes

| Type     | Remarks                                                      |
| -------- | ------------------------------------------------------------ |
| `char`   | **a single byte**, capable of holding one character in the local character set |
| `int`    |                                                              |
| `float`  | single-precision floating point                              |
| `double` | double-precision floating point                              |

### Qualifiers

- `short int` == `short`
- `long int` == `long`

`short` is often 16 bits long, and `int` either 16 or 32 bits. Each compiler is free to choose appropriate sizes for its own hardware, subject only the restriction that `short`s and `int`s are at least 16 bits, `long`s are at least 32 bits, and `short` is no longer than `int`, which is no longer than `long`.

## Constants

Integer: `lL` long, `uU` unsigned.

Float: `fF` float, `lL` long double.

The value of an integer can be specified in octal or hexadecimal instead of decimal. **A leading 0 (zero) on an integer constant means octal; a leading 0x or 0X means hexadecimal.** For example, **decimal 31 can be written as 037 in octal and 0x1f or 0x1F in hex.** Octal and hexadecimal constants may also be followed by L to make them long and U to make them unsigned: `0XFUL` is an unsigned long constant with value 15 decimal.

Complete set of escape sequences

| Character | Representation         |
| --------- | ---------------------- |
| \a        | alert (bell) character |
| \b        | backspace              |
| \f        | formfeed               |
| \n        | newline                |
| \r        | carriage return        |
| \t        | horizontal tab         |
| \v        | vertical tab           |
| \\\       | backslash              |
| \?        | question mark          |
| \\'       | single quote           |
| \\"       | double quote           |
| \ooo      | octal number           |
| \xhh      | hexadecimal number     |

`\0` represents the character with value zero, the null character. `\0` is often written instead of `0` to emphasize the character nature of some expression, but the numeric value is just 0.

String constants can be concatenated at compile time:

```c
"hello, " "world"
"hello, world"
```

are equivalent.

Technically, a string constant is an array of characters. The internal representation of a string has a `\0` at the end, so the physical storage required is one more than the number of characters written between the quotes.

### Enumeration Constant

The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified. If not all values are specified, unspecified values continue the progression from the last specified value

```c
enum boolean { NO, YES }; /* NO = 0, YES = 1 */
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
               NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB = 2, MAR = 3, etc. */
```

Enumerations provide a convenient way to associate constant values with names, an alternative to `#define` with the advantage that the values can be generated for you. **Although variables of `enum` types may be declared, compilers need not check that what you store in such a variable is a valid value for the enumeration.** Nevertheless, enumeration variables offer the chance of checking and so are often better than `#define`s. In addition, a debugger may be able to print values of enumeration variables in their symbolic form.

## Declarations

All variables must be declared before use, although certain declarations can be made implicitly by content. A declaration specifies a type, and contains a list of one or more variables of that type, as in

```c
int lower, upper, step;
char c, line[1000];
```

A variable may also be initialized in its declaration.

```c
char esc = '\\';
int i = 0;
int limit = MAXLINE+1;
float eps = 1.0e-5;
```

External and static variables are initialized to zero by default. Automatic variables with no explicit initializer have undefined (i.e., garbage) values.

The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed. For an array, the `const` qualifier says that the elements will not be altered.

```c
const double e = 2.71828182845905;
const char msg[] = "warning: ";
```

The `const` declaration can also be used with array arguments, to indicate that the function does not change that array:

```c
int strlen(const char[]);
```

## Arithmetic Operators

`+-*/%`. Integer division truncates any fractional part. `%` cannot be applied to a `float` or `double`.

The direction of truncation for `/` and the sign for the result of `%` are machine-dependent for negative operands, as is the action taken on overflow or underflow.

## Relational and Logical Operators

## Type Conversions

In general, the only automatic conversions are those that convert a "narrower" operand into a "wider" one without losing information, such as converting an integer into floating point in an expression like `f + i`. Expressions that might lose information, like assigning a longer integer type to a shorter, or a floating-point type to an integer, may draw a warning, but they are not illegal.

```c
sqrt((double) n)
```

Casting produces the value of `n` in the proper type; `n` itself is not altered.

## Increment and Decrement Operators

## Bitwise Operators

C provides six operator for bit manipulation; these may only be applied to integral operands, that is `char`, `short`, `int` and `long`, whether signed or unsigned.

`& | ^ << >> ~`

The bitwise AND operator `&` is often used to mask off some set of bits

## Precedence and Order of Evaluation

| Operators                            | Associativity |
| ------------------------------------ | ------------- |
| `() [] -> .`                         | left to right |
| `! ~ ++ -- + - * sizeof` and casting | right to left |
| `* / %`                              | left to right |
| `+ -`                                | left to right |
| `<< >>`                              | left to right |
| `< <= > >=`                          | left to right |
| `== !=`                              | left to right |
| `&`                                  | left to right |
| `^`                                  | left to right |
| `|`                                  | left to right |
| `&&`                                 | left to right |
| `||`                                 | left to right |
| `?:`                                 | right to left |
| `= += -= *= /= %= &= ^= |= <<= >>=`  | right to left |
| `,`                                  | left to right |

Unary `& + - *` have higher precedence than the binary forms.

Note that the precedence of the bitwise operators `& ^ |` falls below `==` and `!=`. This implies that bit-testing expressions must be fully parenthesized to give proper results.

C, like most languages, does not specify the order in which the operands of an operator are evaluated. (The exceptions are `&&`, `||`, `?:`, and `,`.) For example, in a statement like

```c
x = f() + g();
```

`f` may be evaluated before `g` or vice versa; thus if either `f` or `g` alters a variable on which the other depends, `x` can depend on the order of evaluation. Intermediate results can be stored in temporary variables to ensure a particular sequence.

Similarly, the order in which function arguments are evaluated is not specified, so the statement

```c
printf("%d %d\n", ++n, power(2, n)); /* WRONG */
```

can produce different results with different compilers, depending on whether `n` is incremented before power is called. The solution is to write

```c
++n;
printf("%d %d\n", n, power(2, n));
```

The moral is that writing code that depends on order of evaluation is a bad programming practice in any language. Naturally, it is necessary to know what things to avoid, if you don't know how they are done on various machines, you won't be tempted to take advantage of a particular implementation.

# Control Flow

## Switch

## Loops - While and For

```c
for (expr1; expr2; expr2)
    statement
```

is equivalent to

```c
expr1;
while (expr2) {
    statement;
    expr3;
}
```

```c
for (;;) {
    ...
}
```

is an "infinite" loop, presumably to be broken by other means, such as `break` or `return`.

## Loops - Do-While

## Goto and labels

# Functions and Program Structure

Source files may be compiled separately and loaded together, along with previously compiled functions from libraries.

## External Variables



## The C Preprocessor

conceptually a separate first step in compilation.

A pointer is a variable that contains the address of a variable.

- `#include`: include the contents of a file during compilation.
- `#define`: to replace a token by an arbitrary sequence of characters.

### File Inclusion

```c
#include "filename"
#include <filename>
```

If the filename is quoted, searching for the file begins where the source program was found; if it is not found there, or if the name is enclosed in `<` and `>`, searching follows an implementation-defined rules to find the file. An included file may itself contains `#include` lines.

`#include` is the preferred way to tie the declarations together for a large program. It guarantees that all the source files will be supplied with the same definitions and variable declarations, and thus eliminates a particularly nasty kind of bug. Naturally, when an included file is changed, all files that depend on it must be recompiled.

### Macro Substitution

```c
#define name replacement text
```

This calls for a macro substitution of the simplest kind - subsequent occurrences of the token `name` will be replaced by the `replacement text`. Normally the replacement text is the rest of the line, but a long definition may be continued onto several lines by placing a `\` at the end of each line to be continued. The scope of a name defined with `#define` is from its point of definition to the end of the source file being compiled. A definition may use previous definitions. Substitutions are made only for tokens, and do not take place within quoted strings. For example, if `YES` is a defined name, there would be no substitution in `printf("YES")` or in `YESMAN`.

```c
#define forever for (;;) /* infinite loop */
```

It is also possible to define macros with arguments, so the replacement text can be different for different calls of the macro. Although it looks like a function call, a use of `max` expands into in-line code. Each occurence of a formal parameter (here `A` or `B`) will be replaced by the corresponding actual argument.

```c
#define max(A, B) ((A) > (B) ? (A) : (B))
x = max(p+q, r+s);
x = ((p+q) > (r+s) ? (p+q) : (r+s));
```

If you examine the expansion of `max`, you will notice some pitfalls. The expressions are evaluated twice; this is bad if they involve side effects like increment operators or input and output. For instance

```c
max(i++, j++) /* WRONG */
```

will increment the larger twice. Some care also has to be taken with parentheses to make sure the order of evaluation is preserved; consider what happens when the macro is invoked as `square(z+1)`.

```c
#define square(x) x * x /* WRONG */
```

------

Names may be undefined with `#undef`, usually to **ensure that a routine is really a function not a macro.**

```c
#undef getchar
int getchar(void) { ... }
```

Formal parameters are not replaced within quoted strings. If a parameter name is preceded by a `#` in the replacement text, the combination will be expanded into a quoted string with the parameter replaced by the actual argument. This can be combined with string concatenation to make, for example, a debugging print macro yields:

```c
#define dprint(expr) printf(#expr " = %d\n", expr)
dprint(x/y)
printf("x/y" " = %g\n", expr);
printf("x/y = %g\n", x/y);
```

Within the actual argument, each `"` is replaced `\"` and each `\` by `\\`, so the result is a legal string constant.

------

The preprocessor operator `##` provides a way to concatenate actual arguments during macro expansion. If a parameter in the replacement text is adjacent to a `##`, the parameter is replaced by the actual argument, the `##` and surrounding white space are removed, and the result is rescanned. For example, the macro `paste` concatenates its two arguments:

```c
#define paste(front, back) front ## back
```

so `paste(name, 1)` creates the token `name1`.

### Conditional Inclusion

This provides a way to include code selectively, depending on the value of conditions evaluated during compilation.

The `#if` line evaluates a constant integer expression (which may not include `sizeof`, casts or `enum` constants). If the expression is nonzero, subsequent lines until an `#endif` or `#elif` or `#else` are included. (The preprocessor statement `#elif` is like `else-if`.) The expression `defined(name)` in a `#if` is 1 if the `name` has been defined, and 0 otherwise.

For example, to make sure that the contents of a file `hdr.h` are included only once, the contents of the file are surrounded with a conditional like this:

```c
#if !defined(HDR)
#define HDR

/* contents of hdr.h go here */

#endif
```

The first inclusion of  `hdr.h` defines the name `HDR`; subsequnt inclusions will find the name defined and skip down to the `#endif`. A similar style can be used to avoid including files multiple times. If this style is used consistently, then **each header can itself include any other headers on which it depends, without the user of the header having to deal with the interdependence.**

This sequence tests the same `SYSTEM` to decide which version of a header to include:

```c
#if SYSTEM == SYSV
	#define HDR "sysv.h"
#elif SYSTEM == BSD
	#define HDR "bsd.h"
#elif SYSTEM == MSDOS
	#define HDR "msdos.h"
#else
	#define HDR "default.h"
#endif
#include HDR
```

The `#ifdef` and `#ifndef` lines are specialised forms that test whether a name is defined. The first example of `#if` above could have been written

```c
#ifndef HDR
#define HDR

/* contents of hdr.h go here */

#endif
```

### Pragmas

A control line of the form

```c
# pragma token-sequence
```

causes the preprocessor to perform an implementation-dependent action. An unrecognised pragma is ignored.

# Pointers and Arrays

## Pointers and Addresses

**The unary operator `&` gives the address of an object**, so the statement

```c
p = &c;
```

assigns the address of `c` to the variable `p`, and `p` is said to "point to" `c`. The `&` operator only applies to objects in memory: variables and array elements. It cannot be applied to expressions, constants, or `register` variables.

**The unary operator `*` is the indirection or dereferencing operator; when applied to a pointer, it accesses the object the pointer points to.** Suppose that `x` and `y` are integers and `ip` is a pointer to `int`. This artificial sequence shows how to declare a pointer and how to use `&` and `*`:

```c
int x = 1, y = 2, z[10];
int *ip; // ip is a pointer to int
ip = &x; // ip now points to x
y = *ip; // y is now 1
*ip = 0; // x is now 0
ip = &z[0]; // ip now points to z[0]
```

```c
double *dp, atof(char *);
```

says that in an expression `*dp` and `*atof(s)` have values of `double`, and that the argument of `atof` is a pointer to `char`.

> Every pointer points to a specific data type. (Exception: "pointer to `void`" is used to hold any type of pointer but cannot be dereferenced itself.)

If `ip` points to the integer `x`, then `*ip` can occur in any context where `x` could, so

```c
*ip = *ip + 10;
```

increments `*ip` by 10.

The unary operators `*` and `&` bind more tightly than arithmetic operators, so the assignment

```c
y = *ip + 1
```

takes whatever `ip` points at, adds 1, and assigns the result to `y`, while

```c
*ip += 1;
++*ip;
(*ip)++;
```

The above three lines increments what `ip` points to. The parantheses are necessary in this last example; without them, the expression would increment `ip` instead of what it points to, because **unary operators like `*` and `++` associate right to left.**

Finally, since pointers are variables, they can be used without dereferencing. For example, if `iq` is another pointer to `int`,

```c
iq = ip
```

copies the contents of `ip` into `iq`, thus making `iq` point to whatever `ip` pointed to.

## Pointers and Function Arguments

Since C passes arguments to functions by value, there is no direct way for the called function to alter a variable in the calling function.

```c
void swap(int x, int y) { /* WRONG */
    int temp;
    
    temp = x;
    x = y;
    y = temp;
}
```

Because of call by value, `swap` can't affect the arguments `a` and `b` in the routine that called it. The function above swaps *copies* of `a` and `b`.

```c
void swap(int *px, int *py) { /* interchange *px and *py */
    int temp;
    
    temp = *px;
    *px = *py;
    *py = temp;
}

swap(&a, &b);
```

```c
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c), c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
```

## Pointers and Arrays

If `pa` points to a particular element of an array, then by definition `pa+1` points to the next element, `pa+i` points `i` elements after `pa` and `pa-i` points `i` elements before. Thus, if `pa` points to `a[0]`,

```c
*(pa+1)
```

refers to the contents of `a[1]`, `pa+i` is the address of `a[i]`, and `*(pa+i)` is the contents of `a[i]`.

> The value of a "variable or expression" of "type = array" is the address of element zero of the array.

```c
// Equivalent statements
pa = &a[0];
pa = a;
```

`pa` and `a` have identical values.

A reference to `a[i]` can also be written as `*(a+i)`. In evaluating `a[i]`, C converts it to `*(a+i)` immediately; the two forms are equivalent. Applying the operator `&` to both parts of this equivalence, it follows that `&a[i]` and `a+i` are also identical. In short, an array-index expression is equivalent to one written as a pointer with offset.

```c
/* strlen: return length of string s */
int strlen(char *s) {
    int n;
    for (n = 0; *s != '\0', s++)
        n++;
    return n;
}
```

Since `s` is a pointer, incrementing it is perfectly legal; `s+` has no effect on the character string in the function that called `strlen`, but merely increments `strlen`'s private copy of the pointer.

```c
strlen("hello, world"); /* string constant */
strlen(array); /* char array[100]; */
strlen(ptr); /* char *ptrl */
```

As formal parameters in a function definition, `char s[]` and `char *s` are equivalent; we prefer the latter because it says more explicitly that the variable is a pointer. When an array name is passed to a function, the function can at its convenience believe that it has been handed either an array or a pointer, and manipulate it accordingly. It can even use both notations if it seems appropriate and clear.

It is possible to pass **part of an array** to a function, by passing a pointer to the beginning of the **subarray**. For example, if `a` is an array,

```c
f(&a[2]);
f(a+2);
```

both pass to the function `f` the address of the subarray that starts at `a[2]`. Within `f`, the parameter declaration can read either

```c
f(int arr[]) { ...  }
f(int *arr) { ... }
```

If one is sure that the elements exist, it is also possible to index backwards in an array; `p[-1]`, `p[-2]`, and so on are syntactically legal, and refer to the elements that immediately precede `p[0]`. **Of course, it is illegal to refer to objects that are not within the array bounds.**

## Address Arithmetic

If `p` is a pointer to some element of an array, then `p++` increments `p` to point to the next element, and `p+=i` increments it to point `i` elements beyond where it currently does.

### Writing a rudimentary storage allocator

1. `alloc(n)` returns a pointer to `n` consecutive character positions, which can be used by the caller of `alloc` for storing characters.
2. `afree(p)` releases the storage thus acquired so it can be reused later.

The storage managed by `alloc` and `afree` is a stack (last in first out). The standard library provides analogous functions called `malloc` and `free` that have no such restrictions.

## Character Pointers and Functions

## Pointer Arrays; Pointers to Pointers

## Multi-dimensional Arrays

## Initialization of Pointer Arrays

## Pointers vs Multi-dimensional Arrays

# Structures

A structure is a collection of one or more variables, possibly of different types, grouped together under a single name for convenient handling. Structures help to organise complicated complicated data, particularly in large programs.

## Basics of Structures

```c
struct point {
    int x;
    int y;
}
```

The keyword `struct` introduces a structure declaration, which is a list of declarations enclosed in braces. An optional name called a *structure tag* may follow the word `struct` (as with `point` here). The tag names this kind of structure, and can be used subsequently as a shorthand for hte part of the declaration in braces.

The variables named in a structure are called *members*.

```c
struct { ... } x, y, z;
int x, y, z;
```

are syntactically analogous to each other. A strucuture declaration that is not followed by a list of variables reserves no storage; it merely describes a template or shape of a structure. If the declaration is tagged, however, the tag can be used later in definitions of instances of the structure.

```c
struct point pt;
```

defines a variable `pt` which is a structure of type `struct point`. A structure can be initialized by following its definition with a list of initializers, each a constant expression, for the members:

```c
struct maxpt = { 320, 200 };
```

An automatic structure may also be initialized by assignment or by calling a function that returns a structure of the right type.

Structures can be nested.

```c
struct rect {
    struct point pt1;
    struct point pt2;
}

struct rect screen;
screen.pt1.x; // refers to x coordinate of the pt1 member of screen.
```

## Structures and Functions

The only legal operations on a structure are copying it or assigning to it as a unit, taking its address with `&`, and accessing its members. Copy and assignment include passing arguments to functions and returning values from functions as well. Structures may not be compared. A structure may be initialized by a list of constant member values; an automatic structure may also be initialized by an assignment.

```c
/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct rect screen;
struct point middle;
screen.pt1 = makepoint(0,0);
screen.pt2 = makepoint(XMAX, YMAX);
middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                   (screen.pt1.y + screen.pt2.y)/2);

/* addpoints: add two points */
struct addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}
```

If a large strucuture is to be passed to a function, it is generally more efficient to pass a pointer than to copy the whole structure. Structure pointers are just like pointers to ordinary variables.

```c
struct point *pp;
```

says that `pp` is a pointer to a structure of type `struct point`. If `pp` points to a `point` structure, `*pp` is the structure, and `(*pp).x` and `(*pp).y` are the members. To use `pp`, we might write,

```c
struct point origin, *pp;
pp = &origin;
printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
```

The precedence of the structure member operator `.` is higher then `*`. The expression `*pp.x` means `*(pp.x)`, which is illegal here because `x` is not a pointer.

Pointers to structures are so frequently used that an alternative notation is provided as a shorthand. If `p` is a pointer to a structure, then

```
p -> member-of-structure
```

So we could write instead

```c
printf("origin is (%d,%d)\n", pp->x, pp->y);
```

Both `.` and `->` associate from left to right, so if we have

```c
struct rect r, *rp = &r;
// The following 4 statements are equivalent
r.pt1.x;
rp->pt1.x;
(r.pt1).x;
(rp->pt1).x;
```

```c
struct {
    int len;
    char *str;
} *p;

++p->len // ++(p->len)
```

Paranthese can be used to alter binding: `(++p)->len` increments `p` before accessing `len`, and `(p++)->len` increments `p` afterward. In the same way, `*p->str` fetches what ever `str` points to; `*p->str++` increments `str` after accessing whatever it points to (just like `*s++`); `(*p->str)++` increment whatever `str` points to; and `*p++->str` increments `p` after accessing whatever `str` points to.

## Arrays of Structures

## Pointers to Structures

## Self-referential Structures

## Table Lookup

## Typedef

For creating new data type names.

```c
typedef int Length;
```

makes `Length` a synonym for `int`. The type `Length` can be used in declarations, casts, etc., in exactly the same ways that the `int` type can be:

```c
Length len, maxlen;
Length *lengths[];
```

```c
typedef char *String;
String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);
p = (String) malloc(100);
```



## Unions

## Bit-fields

`-> .` sizeof

# Input and Output

## Formatted Output - `printf`

The format string contains two types of objects: ordinary characters, which are copied to the output stream, and conversion specifications, each of which causes conversion and printing of the next successive argument to `printf`. Each conversion specification begins with a `%` and ends with a conversion character. **Between the `%` and the conversion character there may be, in order:**

- **Flags** (in any order), which modify the specification:
  - `-`: which specifies left adjustment of the converted argument.
  - `+`: which specifies that the number will always be printed with a sign.
  - space" if the first character is not a sign, a space will be prefixed.
  - `0`: for numeric conversions, specifies padding to the field width with leading zeros.
  - `#`: which specifies an alternate output form.
- **A number specifying a minimum field width**. The converted argument will be printed in a field at least this wide. ***If the necessary it will be padded on the left (or right, if left adjustment is called for) to make up the field width.***
- A **period**, which **separates the field width from the precision**.
- A number, the **precision**, that specifies the maximum number of characters to be printed from a string, or the number of digits affter the decimal point of a floating-point value, or the minimum number of digits for an integer.
- An `h` if the integer is to be printed as a short, or `l` if as a long, `L` indicates that the argument is a long double.

| Character | Argument type; Printed As                                    |
| --------- | ------------------------------------------------------------ |
| `d, i`    | `int`; decimal number                                        |
| `o`       | `int`; unsigned octal number (without a leading zero)        |
| `x, X`    | `int`; unsigned hexadecimal number (without a leading `0x` or `0X`), using `abdef` or `ABCDEF` for 10, ..., 15. |
| `u`       | `int`; unsigned decimal number                               |
| `c`       | `int`; single character                                      |
| `s`       | `char *`; print characters from the string until a '`\0`' or the number of characters given by the precision. |
| `f`       | `double`; `[-]m.dddddd`, where the number of `d`'s is given by the precision (default 6). |
| `e, E`    | `double`; `[-]m.dddddde+/-xx` or `[-]m.ddddddE+/-xx`, where the number of `d`'s is given by the precision (default 6). |
| `g, G`    | `double`; use `%e` or `%E` if the exponent is less than -4 or greater than or equal to the precision; otherwise use `%f`. Trailing zeros and a trailing decimal point are not printed. |
| `p`       | `void *`; pointer                                            |
| `%`       | no argument is converted; print a `%`                        |

A width or precision may be specified as `*`, in which case the value is computed by converting the next argument (which must be an int). For example, to print at most `max` characters from a string `s = "hello, world"`,

```c
printf("%.*s", max, s);
```

| format string | field               |
| ------------- | ------------------- |
| `%s`          | `:hello, world:`    |
| `%10s`        | `:hello, world:`    |
| `%.10s`       | `:hello, wor:`      |
| `%-10s`       | `:hello, world:`    |
| `%.15s`       | `:hello, world:`    |
| `%-15s`       | `:hello, world   :` |
| `%15.10s`     | `:     hello, wor:` |
| `%-15.10s`    | `:hello, wor     :` |

```c
printf(s); /* FAILS if s contains % */
printf("%s", s); /* SAFE */
```

## Formatted Input - `scanf`

```c
int scanf(char *format, ...)
```

`scanf` reads characters from standard input, interprets them according to the specification in `format`, and stores the results through the remaining arguments. **The other arguments, each of which must be a pointer, indicate where the corresponding converted input should be stored.**

`scanf` stops when it exhausts its format string, or when some input fails to match the control specification. It returns as its value the number of successfully matched and assigned input items. This can be used to decide how many items were found. On the end of file, `EOF` is returned. The next call to `scanf` resumes searching immediately after the last character already converted.

The format string usually contains conversion specifications, which are used to control conversion of input. The format string may contain:

- Blanks or tabs, which are not ignored.
- Ordinary characters (not `%`), which are expected to match the non-white space character of the input stream.
- Conversion specifications, consisting of the character `%`, an **optional assignment suppression character** `*`, an **optional number specifying a maximum field width**, an **optional `h`, `l` or `L` indicating the width of the target**, and a conversion character.

Normally the result is placed in the variable pointed to by the corresponding argument. If assignment suppression is indicated by `*`, as in `%*s`, the input field is skipped; no assignment is made. An input field is defined as a string of non-white space characters; it extends either to the next white space character or until the field width, is specified, is exhausted. This implies that `scanf` will read across boundaries to find its input, since newlines are white space. (White space characters are blank, tab, newline, carriage return, vertical tab, and formfeed.)

## File Access

`fopen` takes an external name like `x.c` or `y.c`, does some housekeeping and negotiation with the operating system (details of which needn't concern us), and returns a pointer to be used in subsequent reads or writes of the file.

This pointer, called the *file pointer*, points to a structure that contains information about the file, such as the location of buffer, the current character position in the buffer, whether the file is being read or written, and whether errors or end of file have occurred.

```c
FILE *fp;
FILE *fopen(char *name, char *mode);
```

This says that `fp` is a pointer to a `FILE`, and `fopen` returns a pointer to a `FILE`. Notice that `FILE` is a type name, like `int`, not a structure tag; it is defined with a `typedef`.

```c
fp = fopen(name, mode);
```

The first argument of `fopen` is a character string containing the name of the file. The second argument is the *mode*, also a character string, which indicates how one intends to use the file. Allowable modes include read (`"r"`), write (`"w"`), and append (`"a"`). Some systems distinguish between text and binary files; for the latter, a `"b"` must be appended to the mode string.

If a file that does not exist is opened for writing or appending, it is created if possible. Opening an existing file for writing causes the old contents to be discarded, while opening for appending preserves them. Trying to read a file that does not exist is an error, and there may be other causes of error as well, like trying to read a file when you don't have permission. If there is any error, `fopen` will return `NULL`.

------

```c
int getc(FILE *fp)
```

`getc` returns the next character from the stream referred to by `fp`; it returns `EOF` for end of file or error.

```c
int putc(int c, FILE *fp)
```

`putc` writes character `c` to the file `fp` and returns the character written, or EOF if an error occurs.

------

When a C program is started, the operating system environment is responsible for opening three files and providing pointers for them. These files are `stdin`, `stdout`, and `stderr`, and are declared in `<stdio.h>`. Normally `stdin` is connected to the keyboard and `stdout` and `stderr` are connected to the screen, but `stdin` and `stdout` may be redirected to files or pipes.

# Standard Library

1. Input and Output: `<stdio.h>`
2. Character Class Tests: `<ctype.h`
3. String Functions: `<string.h>`
4. Mathematical Functions: `<math.h>`
5. Utility Functions `<stdlib.h>`
6. Diagnostics `<assert.h>`
7. Variable Argument Lists: `<stdarg.h>`
8. Non-local Jumps: `<setjmp.h>`
9. Signals: `<signal.h>`
10. Date and Time Functions: `<time.h>`
11. Implementation-defined Limits: `<limits.h>` and `<float.h>`