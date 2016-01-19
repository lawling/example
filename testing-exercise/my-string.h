#if !defined(MY_STRING_H)
#define MY_STRING_H

typedef struct char_node {
  char ch;
  struct char_node *next;
} Node;

typedef struct string {
  Node *head;
  Node *tail;
} My_string;

/* It is valid to pass the same My_string into both parameters of functions
 * that have two My_string parameters.  The functions that have a pointer to
 * a My_string as a parameter should all have no effect if NULL is passed in.
 */


/*********** My_string initialization and destruction functions ***********/

/* Initializes a My_string.  Must be called on any My_string variable before
 * it can be passed into any of the other functions.
 */
void init(My_string *s);

/* Removes all of the characters in s and frees any memory that s had used. */
void clear(My_string *s);


/******************* Functions to create My_strings *******************/

/* Adds all the characters of t to the end of s.  If s and t are the same
   string its contents would be repeated, for example, if s contained
   "choo", after append(&s, s) it should become "choochoo".
 */
void append(My_string *s, const My_string t);

/* Replaces the current contents of s (freeing all memory used) with the
 * characters of the C string str.
 */
void assign(My_string *s, const char str[]);

/* Replaces the current contents of s (freeing all memory used) with the
 * characters of t.  copy() should have no effect if the same string is
 * passed into both s and t.
 */
void copy(My_string *s, const My_string t);


/*************** Length, comparison, and print functions ***************/

/* Returns the number of characters in s. */
int length(const My_string s);

/* Returns 1 if s and t have all the same characters in the same order, and
 * 0 otherwise.
 */
int equal(const My_string s, const My_string t);

/* Prints the characters of s. */
void print(const My_string s);


/*********** Search and replace functions.  These functions consider the first
 *********** character in a My_string to be at position 0.  *******/

/* Searches for t in s; if it is present returns the position in s where t
 * begins (the first occurrence of it), or -1 if t isn't found in s.  If t
 * has no characters (an empty string), 0 will be returned.
 */
int find(const My_string s, const My_string t);

/* t gets the characters of s starting at start_pos, and consisting of the
 * num_chars that begin there, and 1 is returned.  For instance, if s
 * contains "abcdefghijk", after calling substring(s, 2, 4, &t) t would
 * contain "cdef".  If the range s[start_pos]..s[start_pos + num_chars - 1]
 * would lie entirely or partly outside of s, or start_pos or num_chars are
 * negative, t should not be modified and 0 should be returned instead.
 * Should just return 0 if t is NULL.
 */
int substring(const My_string s, int start_pos, int num_chars, My_string *t);

/* The characters in s in the range s[start_pos]..s[start_pos + num_chars -
 * 1] should be replaced by the value of t, and 1 is returned.  For
 * instance, if s contains "abcdefghijk", and t is "vwxyz", then after
 * calling replace_between(&s, 3, 4, t) s would contain "abcvwxyzhijk".  If
 * the range s[start_pos]..s[start_pos + num_chars - 1] would lie entirely
 * or partly outside of s, or start_pos or num_chars are negative, s should
 * not be modified and 0 should be returned instead.  Should just return 0
 * if s is NULL.
 */
int replace_between(My_string *s, int start_pos, int num_chars, My_string t);

#endif
