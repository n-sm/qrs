BEGIN { 
    ## FS="[ \t]"
    printf ("En Begin")
    
}
# Code below will execute for each line in file.
{
    x=1  # Set initial word index to 1 (0 is the original string in array)
    fw=1 # Indicate that future matched word is a first word. This is needed to put newline and spaces correctly.
    while ( x<=NF )
    {
        gsub(/[ \t]*/,"",$x) # Strip word. Remove any leading and trailing white-spaces.
        if (!match($x,"^[A-Za-z0-9]*$")) # Print word only if it does not match pure alphanumeric set of characters.
        {
            if (fw == 0)
            {
                printf (" %s", $x) # Print the word offsetting it with space in case if this is not a first match.
            }
            else
            {
                printf ("%s", $x) # Print word as is...
                fw=0 # ...and indicate that future matches are not first occurrences
            }
        }
        x++ # Increase word index number.
    }
    if (fw == 0) # Print newline only if we had matched some words and printed something.
    {
        printf ("\n")
    }
}
