library(RcppAnnoy)

f <- 3

# create a new Annoy instance of type AnnoyAngular
# f is the length of the vectors that the Annoy instance will be indexing
a <- new(AnnoyAngular, f)

# add item i (e.g. 0) with vector v (e.g. c(0,0,1))
a$addItem(0, c(0,0,1))
a$addItem(1, c(0,1,0))
a$addItem(2, c(1,0,0))

# build a forest of n_trees trees
# more trees == higher precision
# after calling build, no more trees can be added
a$build(100)


# Return the n closest items as an integer vector of indices
a$getNNsByVector(c(3,2,1), 3) # 2 1 0
a$getNNsByVector(c(1,2,3), 3) # 0 1 2
a$getNNsByVector(c(2,0,1), 3) # 2 0 1


# BUILDING ANNOY INDEX ---------------------------------------------------------
vector_size <- 10
a <- new(AnnoyEuclidean, vector_size)

a$setSeed(42)

# Turn on verbose status messages (0 to turn off)
a$setVerbose(1)

# Load 100 random vectors into index
for (i in 1:100) a$addItem(i - 1, runif(vector_size)) # Annoy uses zero indexing

# Display number of items in index
a$getNItems()

# Retrieve item at postition 0 in index
a$getItemsVector(0)

# Calculate distance between items at postitions 0 & 1 in index
a$getDistance(0, 1)

# Build forest with 50 trees
a$build(50)

# PERFORMING ANNOY SEARCH ------------------------------------------------------
# Retrieve 5 nearest neighbors to item 0
# Returned as integer vector of indices
a$getNNsByItem(0, 5)
# Retrieve 5 nearest neighbors to item 0
# search_k = -1 will invoke default search_k value of n_trees * n
# Return results as list with an element for distance
a$getNNsByItemList(0, 5, -1, TRUE)

# Retrieve 5 nearest neighbors to item 0
# search_k = -1 will invoke default search_k value of n_trees * n
# Return results as list without an element for distance
a$getNNsByItemList(0, 5, -1, FALSE)
v <- runif(vector_size)
# Retrieve 5 nearest neighbors to vector v
# Returned as integer vector of indices
a$getNNsByVector(v, 5)
# Retrieve 5 nearest neighbors to vector v
# search_k = -1 will invoke default search_k value of n_trees * n
# Return results as list with an element for distance
a$getNNsByVectorList(v, 5, -1, TRUE)
# Retrieve 5 nearest neighbors to vector v
# search_k = -1 will invoke default search_k value of n_trees * n
# Return results as list with an element for distance
a$getNNsByVectorList(v, 5, -1, TRUE)
# SAVING/LOADING ANNOY INDEX ---------------------------------------------------
# Create a tempfile, replace with a local file to keep
treefile <- tempfile(pattern="annoy", fileext="tree")
# Save annoy tree to disk
a$save(treefile)
# Load annoy tree from disk
a$load(treefile)
# Unload index from memory
a$unload()
