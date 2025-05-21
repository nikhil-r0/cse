import plotly.graph_objects as go
import plotly.express as px
import numpy as np

data = {
'City': ['New York', 'San Francisco', 'Los Angeles', 'Chicago', 'Houston'],
'Lat': [40.7128, 37.7749, 34.0522, 41.8781, 29.7604],
'Lon': [-74.0060, - 122.4194, - 118.2437, -87.6298, -95.3698],
'Population': [8175133, 870887, 3971883, 2716000, 2328000]
}

fig = px.scatter_geo(data,lat='Lat',lon='Lon',size='Population',text='City',projection='natural earth')
fig.update_layout(title = "3D Scatter Plot")
fig.update_traces(textposition = 'top center')
fig.show()
