fn main() {
    /*
    - fn keyword to declare new functions
    - convention: snake case --> all letters lowercase and underscores separate words
    */
    another_function();
    /*
    NOTE: another_function() is declared and defined after the main function. 
        --> This would not in work in C --> the function would have to be at least declared before the main function
        --> in Rust, it doesn't matter, as long as the function is declared somewhere in the file
    */

    /* PARAMETERS --> ARGUMENTS
    - Parameters must declare the type of each variable
        --> advantage: type declarations are not required almost anywhere else in code
    - multiple parameters separated with commas
    Example: 
    */
    get_character_and_number('a',30);                                   // the values of parameters passed in a function are called arguments

    /* STATEMENTS AND EXPRESSIONS
    - Statements: instructions that perform some action and do not return a value
        --> e.g. creating a variable and assigning a value to it with the let keyword, e.g. let y = 6;
        --> function definitions are also statements
        --> statements do not return a value: for example, this gives an error
        let x = (let y = 7);
        Because, let y=7 does not return any value which can be assigned to x
        THIS IS DIFFERENT TO C:
            --> in C, the assignment returns the value, so following example works:
            x = y = 6; --> both x and y have the value 6

    - Expressions: evaluate to a resulting value
    --> can be embedded in statements
    --> calling a function or a macro is an Expression
    Example: 
    */
    let y = {                                   // this is an expression block which returns 4, which is assigned to y
        let x = 3;                              
        x + 1                                   // NOTE: expressions do not include ending semicolon. Adding a semicolon turns this into a statement, which does not return a value. 
    };
    println!("The value of y is: {}", y);

    /* FUNCTIONS WITH RETURN VALUES
    - Type of return values is declared with an -> arrow
    - return value is the final expression in the function
    - earlier values in the function can be returned using the return keyword
    Example:
    */
    let x = function_with_return_value();                           // value returned from the function is used to initialize x
    println!("function with return value of: {}", x); 
    let y = y_plus_one(x);                                          // x is provided as an argument to the function
    println!("value of y calculated through function is: {}", y); 

}

fn another_function() {
    println!("Another Function");
}

fn get_character_and_number(character: char, number: i32) {
    println!("the character is {} and the number is {}", character, number);
}

fn function_with_return_value() -> i32 {                    // no parameters
    5                                                       // no semicolon, because this is an expression whose value we want to return
}

fn y_plus_one(number: i32) -> i32 {                                 // parameter of the function is of type i32 and the function returns a value of type i32 
    number + 1                                                      // expression to be returned --> therefore no semicolon
}