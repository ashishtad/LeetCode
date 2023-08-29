/**
* 71. Simplify Path

* Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

* In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

* The canonical path should have the following format:

* The path starts with a single slash '/'.
* Any two directories are separated by a single slash '/'.
* The path does not end with a trailing '/'.
* The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
* Return the simplified canonical path.
*
* Example 1:

*	Input: path = "/home/"
	Output: "/home"
*	Explanation: Note that there is no trailing slash after the last directory name.
	Example 2:
*
	Input: path = "/../"
*	Output: "/"
	Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
	Example 3:
*
	Input: path = "/home//foo/"
	Output: "/home/foo"
*	Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
	 

*	Constraints:

*	1 <= path.length <= 3000
	path consists of English letters, digits, period '.', slash '/' or '_'.
	path is a valid absolute Unix path.
**/



/**
*	Approach:
*   Use stack to store the path directories name only [ not with "/" or "../"]. Skip the / and .
*   If encountered ".." then delete the up level or parent directory.
*    Once the stack is framed, pop the elements and store them in a string in reverse order.
*
*   Time Complexity: O(n)
*    Space Complexity: O(n)
**/


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirStack; // Stack to hold canonical path components
        stringstream resultStream; // Stream to build the simplified path
        string component; // Variable to store each component of the path
        
        stringstream pathStream(path); // Convert input path to a stream for easy parsing
        //Get th each directory name.
        while (getline(pathStream, component, '/')) {
        
            if (component.empty() || component == ".") {
                // Skip empty components and "." components
                continue;
            } else if (component == "..") {
                if (!dirStack.empty()) {
                    // Handle parent directory ".." by popping from stack
                    dirStack.pop();
                }
            } else {
                // Push valid directory components onto the stack
                dirStack.push(component);
            }
        }
        
        string resultPath = "";
        while (!dirStack.empty()) {
            //Append the stack elements at begin of the string as stac elemnts are in reverse order
            resultPath = "/" + dirStack.top() + resultPath;
            dirStack.pop();
        }
        //If result is empty then return "/"
        return resultPath.empty() ? "/" : resultPath;
    }
};
