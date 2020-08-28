const {expect, it} = require('@jest/globals');
const divide = require('../src/index');

it('should give expected divide floating error', async () => {
  const result = divide(85500000, 1430016);
  expect(typeof result).toBe('string');
  expect(result).toEqual('59.789539337158203');
});

it('should give second expected divide floating error', async () => {
  const result = divide(148352000, 2475000);
  expect(typeof result).toBe('string');
  expect(result).toEqual('59.940200805664062');
});

it('should give round values after dot', async () => {
  const result = divide(71000000, 1185120);
  expect(typeof result).toBe('string');
  expect(result).toEqual('59.9095458984375');
});

it('should give round values after dot', async () => {
  const result = divide(57284000, 768384);
  expect(typeof result).toBe('string');
  expect(result).toEqual('74.55126953125');
});

it('should give round values without dot', async () => {
  const result = divide(108000000, 1800000);
  expect(typeof result).toBe('string');
  expect(result).toEqual('60');
});
