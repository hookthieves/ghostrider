# ghostrider

## Information
Adversaries may smuggle data and files past content filters by hiding malicious payloads inside of seemingly benign HTML files. HTML documents can store large binary objects known as JavaScript Blobs (immutable data that represents raw bytes) that can later be constructed into file-like objects

## HTML Smuggle Logic
1. Payload is encoded in base64 to avoid bad characters
2. Decode routine is used to decode back to its original format
3. Stores into a byte array
4. Places the array into a Blob which gives it a name called sharp.js
5. If the statement detects if the victim is using Chrome or Internet explorer, it will open automatically.
6. Create a hidden a’ tag
7. Create an anchor object with the create element, specifying the anchor object with the hidden a’ tag
8. Place the anchor object into the HTML document and specify its attributes as none, so it does not display on the website
9. With the anchor ready referencing the blob object, an automatic download click is created to download the file automatically.

## Usage
ghostrider.exe input_file

![image](https://github.com/hookthieves/ghostrider/assets/46670348/23094a9a-adf5-471f-97f7-fda52a83e43e)
