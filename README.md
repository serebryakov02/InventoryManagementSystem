# InventoryManagementSystem

The application was primarily developed to demonstrate proficiency and a deep understanding of the Qt Model-View architecture. It features a custom table model (supporting both reading and writing) for data representation, as well as several custom delegates:
- an image delegate for displaying product images within the table
- a supplier delegate with a styled drop-down list for selecting a supplier
- a rating delegate that uses custom painting to allow intuitive star-based rating

In addition, the application implements JSON-based data handling. It uses a JSON file as its internal data storage. If the user makes any modifications, the application will prompt them to confirm or discard the changes. Upon confirmation, the file will be updated. When launched, the application automatically loads the data from this file.

![demo](https://github.com/user-attachments/assets/30dbac75-67cb-456f-b342-a726c808c9fe)
