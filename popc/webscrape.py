from lxml import html
import requests

# Define the URL of the website to scrape
url = 'https://results.vtu.ac.in/DJcbcs24/index.php'

# Send an HTTP request to the website and retrieve the HTML content
response = requests.get(url)

# Parse the HTML content using lxml
tree = html.fromstring(response.content)

# Extract specific elements from the HTML tree using XPath
# For example, let's extract the titles of all the links on the page
link_titles = tree.xpath('//a/text()')

# Print the extracted link titles
for title in link_titles:
    print(title)
