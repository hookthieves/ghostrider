# ghostrider

## Information
This project is to simplify HTML smuggling for red team operations. The idea of this program is to automate the many steps that is required to smuggle a file into a corporate network. 

## HTML Smuggle Logic
1. Payload is encoded in base64 to avoid bad characters
2. Decode routine is used to decode back to its original format
3. Stores into a byte array
4. Places the array into a Blob which gives it a file name
5. If the statement detects if the victim is using Chrome or Internet explorer, it will open automatically
6. Create a hidden a’ tag
7. Create an anchor object with the create element, specifying the anchor object with the hidden a’ tag
8. Place the anchor object into the HTML document and specify its attributes as none, so it does not display on the website
9. With the anchor ready referencing the blob object, an automatic download click is created to download the file automatically

## Usage
- ghostrider.exe input_file
- smuggle.html will be created in the current working directory ready for delivery.

## Todo
1. HTML encode the output and over-write the file to bypasses content inspection

2. ## Licence
MIT Licence @ [MIT](https://raw.githubusercontent.com/hookthieves/ghostrider/main/LICENCE)

## Output
![image](https://github.com/hookthieves/ghostrider/assets/46670348/23094a9a-adf5-471f-97f7-fda52a83e43e)
