Ghostrider

Overview
**Ghostrider** is a **C program** designed to **simplify HTML smuggling** for **red team operations**. The tool automates the process of smuggling a file into a **corporate network** by encoding a payload in **Base64**, embedding it in an **HTML file** with JavaScript, and triggering an automatic download. This technique helps bypass **content inspection** and **security controls** by delivering the payload as a downloadable file via a browser.

Intention
The project aims to **automate** the multi-step process of **HTML smuggling**, reducing the manual effort required in **red teaming operations** and enabling efficient **payload delivery** in security research scenarios.

HTML Smuggling Logic
The tool follows these steps to smuggle a file:
1. **Encodes** the payload in **Base64** to avoid bad characters.
2. Includes a **JavaScript decode routine** to convert the Base64 data back to its original format.
3. Stores the decoded data in a **byte array**.
4. Places the array into a **Blob** object, assigning it a **file name**.
5. Detects the victim's browser (**Chrome** or **Internet Explorer**) to trigger an **automatic download**.
6. Creates a **hidden `` tag**.
7. Generates an **anchor object** using `document.createElement`, marked as hidden.
8. Appends the anchor to the **HTML document** with `display: none` to avoid visibility.
9. Triggers an **automatic download** by simulating a click on the anchor, referencing the **Blob** object.

Features
- **Base64 Encoding**: Encodes any input file to **Base64** for safe transport.
- **Automated HTML Generation**: Creates an HTML file (`smuggle.html`) with embedded **JavaScript** for payload delivery.
- **Browser Compatibility**: Supports **Chrome** and **Internet Explorer** with conditional download logic.
- **Error Handling**: Includes checks for **file operations** and **memory allocation**.
- **Automatic Download**: Triggers the payload download without user interaction.

Prerequisites
- A **C compiler** (e.g., MSVC, gcc).
- **Windows environment** (for file operations and compilation).
- A **web browser** (e.g., Chrome, Internet Explorer) for testing the generated HTML file.
- Basic understanding of **HTML smuggling** and **red teaming**.

Usage

Compilation
Compile the program using a **C compiler**. Examples:
- **MSVC**: `cl main.c`
- **gcc**: `gcc main.c -o ghostrider`

Running the Program
Execute the compiled program with an input file:
```bash
./ghostrider 
```

The program will:

Read the specified input file.
Base64-encode the file's contents.
Generate an HTML file (smuggle.html) with JavaScript to decode and download the payload.
Save smuggle.html in the current working directory, ready for delivery.

Example
Run the program with an input file:

        ###########################################################
        #         Ghostrider - Designed By Cuong Nguyen           #
        ###########################################################

[!] HTML Smuggle created successfully[i] Press  to exit program

Deliver `smuggle.html` to the target (e.g., via a web server or email). When opened in a browser, it will automatically download the original file.

<h3>Output</h3>
The program generates `smuggle.html` in the **current working directory**, which triggers an automatic download when opened in a browser.

![Output Image](https://github.com/hookthieves/ghostrider/assets/46670348/23094a9a-adf5-471f-97f7-fda52a83e43e)

<h2>Code Structure</h2>
- **base64Encode**: Encodes the input file into **Base64** format.
- **main**: Reads the input file, performs **Base64 encoding**, and generates the **HTML file** with embedded **JavaScript** for payload delivery.
- Uses **fopen**, **fread**, and **fwrite** for file operations.
- Uses **malloc** and **free** for memory management.
- Embeds **JavaScript** logic to handle **Blob creation**, **browser detection**, and **automatic download**.

<h2>Notes</h2>
- **Input File**: The program accepts any file as input, but ensure it is compatible with the target environment.
- **Evasion**: **Base64 encoding** and **HTML smuggling** help bypass **content inspection**, but dynamic analysis may detect the download behavior.
- **Limitations**: The generated HTML relies on **JavaScript execution** in the browser, which may be blocked by security controls. The output file is not yet **HTML-encoded** for additional evasion.
- **Browser Support**: Tested with **Chrome** and **Internet Explorer**. Other browsers may require additional testing.

<h2>Testing</h2>
- Test in a **controlled environment** (e.g., a virtual machine with Chrome or Internet Explorer).
- Verify that `smuggle.html` is generated correctly and triggers the download when opened.
- Test with different **input files** (e.g., executables, documents) to ensure compatibility.
- Use **web proxies** or **EDR tools** to assess detection during delivery and execution.
- Inspect the generated HTML in a **text editor** to confirm the **Base64 payload** and **JavaScript logic**.

<h2>To-Do</h2>
- [ ] **HTML-encode** the output and overwrite the file to bypass **content inspection**.
- [ ] Add support for **obfuscating JavaScript** to evade detection.
- [ ] Implement **command-line options** for customizing the output file name or Blob type.
- [ ] Add **error handling** for invalid input files or large payloads.

<h2>License</h2>
This project is licensed under the **MIT License**. See the [LICENSE](https://raw.githubusercontent.com/hookthieves/ghostrider/main/LICENCE) file for details.

<h2>Legal and Ethical Considerations</h2>
This tool is for **educational and research purposes only**. It demonstrates an **HTML smuggling technique** for security research. Ensure compliance with all applicable **laws** and **ethical guidelines** when using this code, especially in **red teaming** or **evasion-focused research**.

<h2>Contact</h2>
For questions or contributions, please contact the project maintainer (Cuong Nguyen) or open an issue on the [GitHub repository](https://github.com/hookthieves/ghostrider).

