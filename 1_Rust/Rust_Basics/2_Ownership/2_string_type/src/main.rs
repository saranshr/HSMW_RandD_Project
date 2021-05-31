fn main() {
    /*
    - The data types discussed until now can be stored on the stack and popped off the stack once their scope is over
    - We now want to explore how data is stored on the heap using Strings
    let s = "hello"         This is a string literal
    - String literals may not always be suitable, because:
        - they are hardcoded into the program
        - they are immutable
        - not every string value can be known while writing the code (e.g. obtaining user input)
        --> Rust has a second string type: String
        --> a String can be created from a string literal using the from function:
    */
    let mut s = String::from("hello");          // :: is an operator that allows us to namespace this particular from Function under the String type rather than using some sort of name like string_from

    s.push_str(", world!");                     // push_str() appends a literal to a string --> included in the standard library
    println!("{}", s);

    /* MEMORY AND ALLOCATION
    - String literal:
        -> hardcoded into final executable
        -> therefore immutable and thus fast/efficient
        -> not possible for unknown sized (at compile time) strings/texts
    - String type:
        -> supports a mutable, growable piece of text
        -> memory must be allocated on the heap, unknown at compile time
            1. Memory must be requested from the OS at runtime --> done via String::from --> this is universal in programming languages
            2. Memory must be returned to the OS at runtime when we're out of the scope of that String
                -> in languages with a Garbage collector (GC), the GC keeps track and cleans up memory that isn't being used anymore
                -> without a GC, the programmer needs to explicitly return it --> difficult task to keep track off
                -> Therefore, in Rust, the memory is automatically returned once the variable that owns it goes out of scope
                -> Rust does this using the function drop, which is called automatically (in the case here, the scope of s ends at
                the curly brackets of the main function, where the drop function would be called freeing the memory of s on the heap automatically)
    */
}
