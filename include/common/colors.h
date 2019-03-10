/*
 * Copyright (c) 2019 Lince99
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/*
 * library dedicated only to define constant string that change text color
 * or background on terminals that support ANSI escape characters
 */
/*
 * https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
 */

#ifndef COLORS_H
#define COLORS_H



//move cursor
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
/*
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}
*/

/*
 * \x1b[38;2;r;g;b
 * \x1b[48;2;r;g;b
 * for any supported color of text and background
 */

//clear the screen
#ifndef ANSI_CLEAN
    #define ANSI_CLEAN "\x1b[H\x1b[J"
#endif

//font colors (foreground)
#ifndef ANSI_BLACK
    #define ANSI_BLACK "\x1b[30m"
#endif

#ifndef ANSI_RED
    #define ANSI_RED "\x1b[31m"
#endif

#ifndef ANSI_GREEN
    #define ANSI_GREEN  "\x1b[32m"
#endif

#ifndef ANSI_YELLOW
    #define ANSI_YELLOW  "\x1b[33m"
#endif

#ifndef ANSI_BLUE
    #define ANSI_BLUE    "\x1b[34m"
#endif

#ifndef ANSI_MAGENTA
    #define ANSI_MAGENTA "\x1b[35m"
#endif

#ifndef ANSI_CYAN
    #define ANSI_CYAN    "\x1b[36m"
#endif

#ifndef ANSI_WHITE
    #define ANSI_WHITE     "\x1b[37m"
#endif

//background colors
#ifndef ANSI_BG_BLACK
    #define ANSI_BG_BLACK     "\x1b[40m"
#endif

#ifndef ANSI_BG_RED
    #define ANSI_BG_RED     "\x1b[41m"
#endif

#ifndef ANSI_BG_GREEN
    #define ANSI_BG_GREEN   "\x1b[42m"
#endif

#ifndef ANSI_BG_YELLOW
    #define ANSI_BG_YELLOW  "\x1b[43m"
#endif

#ifndef ANSI_BG_BLUE
    #define ANSI_BG_BLUE    "\x1b[44m"
#endif

#ifndef ANSI_BG_MAGENTA
    #define ANSI_BG_MAGENTA "\x1b[45m"
#endif

#ifndef ANSI_BG_CYAN
    #define ANSI_BG_CYAN    "\x1b[46m"
#endif

#ifndef ANSI_BG_WHITE
    #define ANSI_BG_WHITE     "\x1b[47m"
#endif

#ifndef ANSI_REVERSE
    #define ANSI_REVESE     "\x1b[7m"
#endif

//font styles
#ifndef ANSI_BOLD
    #define ANSI_BOLD    "\x1b[1m"
#endif

#ifndef ANSI_ITALIC
    #define ANSI_ITALIC    "\x1b[3m"
#endif

#ifndef ANSI_UNDERLINE
    #define ANSI_UNDERLINE    "\x1b[4m"
#endif

#ifndef ANSI_NOT_OVERLINE
    #define ANSI_NOT_OVERLINE    "\x1b[24m"
#endif

#ifndef ANSI_OVERLINE
    #define ANSI_OVERLINE    "\x1b[53m"
#endif

//restore the original foreground and background colors
#ifndef ANSI_RESET
    #define ANSI_RESET   "\x1b[0m"
#endif

int printf_error(char* string) {
    return printf(ANSI_RED ANSI_BOLD "%s" ANSI_RESET "\n", string);
}

int printf_warning(char* string) {
    return printf(ANSI_YELLOW "%s" ANSI_RESET "\n", string);
}

int printf_option(char* string) {
    return printf(ANSI_BLUE "%s" ANSI_RESET "\n", string);
}

int printf_correct(char* string) {
    return printf(ANSI_GREEN "%s" ANSI_RESET "\n", string);
}

int printf_doubt(char* string) {
    return printf(ANSI_CYAN ANSI_ITALIC "%s" ANSI_RESET "\n", string);
}

int printf_important(char* string) {
    return printf(ANSI_UNDERLINE "%s" ANSI_RESET "\n", string);
}

int printf_inverted(char* string) {
    return printf(ANSI_BG_WHITE ANSI_BLACK "%s" ANSI_RESET "\n", string);
}

#endif //COLORS_H
