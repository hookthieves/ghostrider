
# Ghostrider

**Ghostrider** is a C-based utility designed to simplify **HTML smuggling** techniques used in **red team operations**. It automates the process of embedding a payload in an HTML file that triggers a download when opened in a browser. This method is effective at bypassing certain **content filters**, **email gateways**, and **security controls**.

---

## Overview

Ghostrider:
- Encodes a payload in **Base64**
- Embeds it in an **HTML file** with embedded JavaScript
- Uses browser-based JavaScript logic to **decode and download** the file automatically

The result is a smuggled file that is delivered through a web browser, often undetected by traditional inspection tools.

---

## Features

- ✅ **Base64 Encoding** of any input file
- ✅ **Automatic HTML Generation** (`smuggle.html`)
- ✅ **Cross-Browser Support** for Chrome and Internet Explorer
- ✅ **JavaScript-Based Auto-Download**
- ✅ Lightweight and standalone; no external dependencies

---

## How HTML Smuggling Works

1. **Input file** is read and **Base64-encoded**.
2. Encoded string is embedded inside a **JavaScript blob**.
3. JavaScript decodes the string and generates a **Blob object**.
4. Browser-specific logic triggers an **automatic file download**.
5. A hidden anchor element (`<a>`) is clicked programmatically.
6. The payload is downloaded to the victim's machine.

---

## Prerequisites

- A **C compiler** (e.g., `gcc`, `cl`)
- **Windows system** (for file operations and testing)
- A modern **browser** (Chrome or Internet Explorer recommended)
- Basic knowledge of **HTML smuggling**, **JavaScript**, and **red teaming**

---

## Compilation

You can compile Ghostrider using a C compiler:

### Using GCC (MinGW or Linux WSL)

```bash
gcc main.c -o ghostrider
````

### Using MSVC

```bash
cl main.c
```

---

## Usage

```bash
./ghostrider <path_to_input_file>
```

### Example

```bash
./ghostrider payload.exe
```

### Output

* Creates a file called `smuggle.html` in the current working directory
* When opened in a browser, `smuggle.html` will automatically trigger a download of `payload.exe`

---

## Output Structure

The generated `smuggle.html` includes:

* Embedded **Base64 payload**
* JavaScript code to:

  * Decode the payload
  * Generate a Blob
  * Create and trigger a hidden anchor link
  * Handle **browser detection** for compatibility

---

## Code Overview

* **`base64Encode()`**
  Reads and encodes the input file into Base64 format.

* **`main()`**
  Handles:

  * Reading input file
  * Encoding
  * HTML + JavaScript generation
  * Writing to `smuggle.html`

* Uses standard C functions:

  * `fopen`, `fread`, `fwrite` for file I/O
  * `malloc`, `free` for memory management

---

## Notes

* **Input Compatibility**: Any file type can be used, but make sure the payload is supported in the target environment.
* **Security Evasion**: Base64 and HTML smuggling help evade basic security checks, but can still be caught by behavioral analysis.
* **Browser Dependency**: Tested on **Chrome** and **IE**. Other browsers may require tweaks.
* **No Encoding Obfuscation**: JavaScript in `smuggle.html` is not obfuscated; this may be a future enhancement.

---

## Testing Tips

* Use in a **sandbox** or **virtual machine**.
* Open `smuggle.html` in:

  * **Chrome** (modern method)
  * **Internet Explorer** (legacy method)
* Monitor with **web proxy tools**, **EDR**, or **traffic analyzers** to test bypass effectiveness.
* Verify that payloads download correctly and remain undetected.

---

## To-Do

* [ ] HTML encode the Base64 payload to increase stealth
* [ ] JavaScript obfuscation for better evasion
* [ ] Support custom file names and MIME types via CLI
* [ ] Add better error handling and size limitations

---

## License

This project is licensed under the **MIT License**.
See the [LICENSE](https://raw.githubusercontent.com/hookthieves/ghostrider/main/LICENCE) file for details.

---

## Legal & Ethical Use

Ghostrider is intended **strictly for educational and authorized testing purposes**.
Any use of this tool outside legal or ethical boundaries (e.g., without permission) is prohibited and may be illegal.

Use responsibly and only in environments where you have **explicit authorization** to test security defenses.

---

## Contact

Project by **Cuong Nguyen**
For support, suggestions, or issues, visit the [GitHub Repository](https://github.com/hookthieves/ghostrider) or open an issue.

