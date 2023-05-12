# Apply graph algorithms to analyze the network structure and connectivity of a real-world social network, such as Facebook or Twitter.

import networkx as nx
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("https://raw.githubusercontent.com/llSourcell/twitter_graph_analysis_demo/master/followers_data.csv")

G = nx.DiGraph()
for index, row in df.iterrows():
    G.add_node(row['screen_name'], followers_count=row['followers_count'])
for index, row in df.iterrows():
    if row['following'] != "":
        following = row['following'].split(", ")
        for f in following:
            if f in G.nodes():
                G.add_edge(f, row['screen_name'])
nx.draw(G, node_size=10, alpha=0.5, with_labels=False)
plt.show()