# this is how it's done in Ripley's original knn algorithm
# we use the version from the FNN library as it allows us to see the
#   actual values of the nearest neighbours (as opposed to just grouping)

library(FNN)

train <- rbind(iris3[1:25,,1], iris3[1:25,,2], iris3[1:25,,3])
test <- rbind(iris3[26:28,,1], iris3[26:28,,2], iris3[26:28,,3])
cl <- factor(c(rep("group1",25), rep("group2",25), rep("group3",25)))
out <- knn(train, test, cl, k = 3, prob = TRUE)

attr(out,"nn.index")

library(RcppAnnoy)


# create a new Annoy instance of type AnnoyAngular
a <- new(AnnoyEuclidean, 4)

for (i in 1:75) {
  a$addItem(i, train[i,])
}

# build a forest of n_trees trees
# more trees == higher precision
# after calling build, no more trees can be added
a$build(100)

for (i in 1:9) {
  print(a$getNNsByVector(test[i,], 3))
}

# compare to FNN's knn output
attr(out,"nn.index")

# results are similar but not exact!
# how about speed? let's try this later on huge datasets
