const {expect, it} = require('@jest/globals');
const divide = require('../src/index').default;

it('should give expected divide floating error', async () => {
  const result = divide(85500000, 1430016);
  expect(typeof result).toBe('string');
  expect(result).toEqual('59.789539337158203');
});
