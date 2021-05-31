fn main() {
    /* DATA TYPES: SCALAR TYPES
    
    --> represent a single value:
        --> integers
        --> floating-point numbers
        --> booleans
        --> characters
    */

    /* INTEGERS

    length      signed      unsigned
    8 Bit       i8          u8
    16 Bit      i16         u16
    32 Bit      i32         u32
    64 Bit      i64         u64
    128 Bit     i128        u128
    arch        isize       usize               --> this depends on the OS (32 bit or 64 bit)

    --> -(2^(n-1)) <= signed <= (2^n) -1
    --> 0 <= unsigned <= (2^n) - 1
    
    --> Integer overflow e.g. entering 256 in an u8 integer --> two's complement wrapping --> 256 becomes 0, 257 becomes 1, etc.
    --> This is considered an error!
    */

    /* FLOATING-POINT TYPES
    - Two primitive floating point numbers: f64 and f32
    --> default is f64
    --> Represented according to the IEEE-754 Standard
        --> f32: single precision float
        --> f64: double precision

    Numeric operations: 
    Division example (addition, subtraction and multiplication are standard)    
    */
    let quotient = 7 / 2;                   // this gives 3, i.e. integer division. Because Rust interprets the numbers as integers by default
    println!("quotient = {}", quotient);

    let quotient = 7.0 / 2.0;                   // this gives 3.5, i.e. floating point division. Now Rust interprets these as floating points
    println!("quotient = {}", quotient);

    let remainder = 43 % 3;
    println!("remainder = {}", remainder);

    /* BOOLEAN TYPE
    --> two possible values: true or false
    --> one byte in size
    --> specified using bool
    */
    let t = true;
    let f:bool = false;         // explicit type annotation

    /* CHARACTER TYPE
    --> alphabet type: char
    --> char literals are specified with single quotes ''
    --> string literals are specified with double quotes ""
    --> char: 4 Bytes in size, Unicode Scalar Value --> i.e. a lot more than ASCII
        --> range from U+0000 to U+D7FF and U+E000 to U+10FFFF inclusive
    Examples:
    */
    let c = 'z';
    let my_name = "Bob";
    println!("c = {}", c);
    println!("my_name = {}", my_name);

    /* COMPOUND TYPES
    - Compound types group multiple values into one type
    --> Tuples
    --> Arrays
    */

    /* TUPLE 
    - grouping together some number of other values with a variety of types into one compound type
    - once declared, they cannot grow or shrink in size
    - type of each element in tuple does not need to be explicitly declared
    Example:
    */
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let tup1 = (500, 6.4, 1);
    let (x, y, z) = tup1;                       // destructuring a tuple
    println!("The value of y is: {}", y);
    println!("The value of y is: {}", tup.1);   // both are valid ways to access tuple elements

    /* ARRAY 
    - each element within array must be of same type
    - arrays have a fixed length, like tuples. --> Also like in C
    - An array is a single chunk of memory allocated on the stack
    --> Not as flexible as so called 'VECTORS'. Vectors are flexible in length. Will be discussed later.
    Example:    
    */
    let d = [1,2,3,4,5];
    let b:[i32; 5] = [1,2,3,4,5];               // not necessary to declare type when array is initialized
    let c:[i32; 10];                            // declare an array without initializing it
    // println!("c[1] is {}",c[1]);              // this is not possible, since c has not yet been initialized
    let a = [3; 5];                             // create a = [3, 3, 3, 3, 3]
    // Accessing an element
    let start = d[0];
    let end = d[a.len()-1];                     // length of array: a.len()
    println!("The value of the first element of d is: {}", start);
    println!("The value of the last element of d is: {}", end);

    // let invalidAccess = a[10];               // this does not produce any compilation errors, but the program exits with a runtime error instead
    /* SAFETY PRINCIPLE
    --> Rust checks if the index specified is less than the array length
    --> if the index is greater than or equal to the length, Rust 'panics'
    --> this check is not performed in most low-level languages, with an incorrect index resulting in invalid memory being access
        --> in C: no error, just a warning: 'array index 10 is past the end of the array (which contains 5 elements)' --> program can be run resulting
        in random value to be accessed.
    */
}
