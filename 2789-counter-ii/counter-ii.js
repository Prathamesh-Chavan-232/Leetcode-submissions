/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let initCount = init;
    let count = initCount;
    return {
      increment: () => {
        count++;
        return count;
      },
      reset: () => {
        count = initCount;
        return count;
      },
      decrement: () => {
        count--;
        return count;
      }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */